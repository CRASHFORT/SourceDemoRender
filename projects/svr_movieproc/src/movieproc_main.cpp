#include <svr/os.hpp>
#include <svr/config.hpp>
#include <svr/log_format.hpp>
#include <svr/graphics.hpp>
#include <svr/graphics_preview.hpp>
#include <svr/ui.hpp>
#include <svr/thread_context.hpp>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <charconv>

static void* arg_to_ptr(const char* arg)
{
    uintptr_t ret;
    std::from_chars(arg, arg + strlen(arg), ret, 16);

    return (void*)ret;
}

int main(int argc, char* argv[])
{
    using namespace svr;

    log_set_function([](void* context, const char* text)
    {
        printf(text);
    }, nullptr);

    char cur_dir[512];

    if (!os_get_current_dir(cur_dir, sizeof(cur_dir)))
    {
        log("Could not get the current directory\n");
        return 1;
    }

    auto start_event = os_open_event("crashfort.movieproc.start");

    auto handle = (os_handle*)arg_to_ptr(argv[0]);

    auto graphics = graphics_create_d3d11_backend(cur_dir);

    graphics_texture_open_desc desc = {};
    desc.view_access = GRAPHICS_VIEW_SRV;

    auto tex = graphics->open_shared_texture("game", handle, desc);
    auto tex_srv = graphics->get_texture_srv(tex);

    thread_context_event ui_thread;
    graphics_preview* prev = nullptr;

    synchro_barrier start_barrier;

    ui_thread.run_task([&]()
    {
        prev = graphics_preview_create_winapi(graphics, 1024, 1024, false);
        start_barrier.open();
        ui_enter_message_loop();
        graphics_preview_destroy(prev);
        prev = nullptr;
    });

    start_barrier.wait();

    auto server_event = os_open_event("crashfort.movieproc.server");
    auto client_event = os_create_event("crashfort.movieproc.client");

    os_set_event(start_event);
    os_close_handle(start_event);

    for (size_t i = 0; i < 64; i++)
    {
        os_reset_event(client_event);

        log("CLIENT: waiting\n");
        os_handle_wait(server_event, -1);
        log("CLIENT: waited\n");

        log("CLIENT: {}\n", i);

        log("CLIENT: rendering\n");
        graphics->lock_shared_texture(tex);
        prev->render(tex_srv);
        graphics->unlock_shared_texture(tex);
        log("CLIENT: rendered\n");

        log("CLIENT: unlocking\n");
        os_set_event(client_event);
        log("CLIENT: unlocked\n");
    }

    int a = 5;
    return 0;
}
