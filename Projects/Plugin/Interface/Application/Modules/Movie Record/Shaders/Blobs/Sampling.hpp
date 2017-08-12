#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
//
// Buffer Definitions: 
//
// cbuffer SharedInputData
// {
//
//   int2 Dimensions;                   // Offset:    0 Size:     8
//
// }
//
// cbuffer InputData
// {
//
//   float Weight;                      // Offset:    0 Size:     4
//
// }
//
// Resource bind info for WorkBuffer
// {
//
//   struct WorkBufferData
//   {
//       
//       float3 Color;                  // Offset:    0
//       float Padding;                 // Offset:   12
//
//   } $Element;                        // Offset:    0 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// SharedTexture                     texture  float4          2d    0        1
// WorkBuffer                            UAV  struct         r/w    0        1
// SharedInputData                   cbuffer      NA          NA    0        1
// InputData                         cbuffer      NA          NA    1        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[1], immediateIndexed
dcl_constantbuffer cb1[1], immediateIndexed
dcl_resource_texture2d (float,float,float,float) t0
dcl_uav_structured u0, 16
dcl_input vThreadID.xyz
dcl_temps 2
dcl_thread_group 8, 8, 1
imad r0.x, vThreadID.y, cb0[0].x, vThreadID.x
ld_structured_indexable(structured_buffer, stride=16)(mixed,mixed,mixed,mixed) r0.yzw, r0.x, l(0), u0.xxyz
ld_indexable(texture2d)(float,float,float,float) r1.xyz, vThreadID.xyzz, t0.xyzw
mad r0.yzw, cb1[0].xxxx, r1.xxyz, r0.yyzw
store_structured u0.xyz, r0.x, l(0), r0.yzwy
ret 
// Approximately 6 instruction slots used
#endif

const BYTE CSBlob_Sampling[] =
{
     68,  88,  66,  67, 244,   8, 
    206, 122, 189, 151,  24,  31, 
    248, 193,  60,  66,  25, 246, 
    132, 183,   1,   0,   0,   0, 
     40,   5,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     60,   3,   0,   0,  76,   3, 
      0,   0,  92,   3,   0,   0, 
    140,   4,   0,   0,  82,  68, 
     69,  70,   0,   3,   0,   0, 
      3,   0,   0,   0, 240,   0, 
      0,   0,   4,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
     83,  67,   0,   1,   0,   0, 
    204,   2,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    188,   0,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 202,   0,   0,   0, 
      6,   0,   0,   0,   6,   0, 
      0,   0,   1,   0,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 213,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    229,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  83, 104,  97, 114, 
    101, 100,  84, 101, 120, 116, 
    117, 114, 101,   0,  87, 111, 
    114, 107,  66, 117, 102, 102, 
    101, 114,   0,  83, 104,  97, 
    114, 101, 100,  73, 110, 112, 
    117, 116,  68,  97, 116,  97, 
      0,  73, 110, 112, 117, 116, 
     68,  97, 116,  97,   0, 171, 
    213,   0,   0,   0,   1,   0, 
      0,   0,  56,   1,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    229,   0,   0,   0,   1,   0, 
      0,   0, 148,   1,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    202,   0,   0,   0,   1,   0, 
      0,   0, 240,   1,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     96,   1,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
      2,   0,   0,   0, 112,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  68, 105, 
    109, 101, 110, 115, 105, 111, 
    110, 115,   0, 105, 110, 116, 
     50,   0,   1,   0,   2,   0, 
      1,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 107,   1, 
      0,   0, 188,   1,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    204,   1,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     87, 101, 105, 103, 104, 116, 
      0, 102, 108, 111,  97, 116, 
      0, 171, 171, 171,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    195,   1,   0,   0,  24,   2, 
      0,   0,   0,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  36,  69, 108, 101, 
    109, 101, 110, 116,   0,  87, 
    111, 114, 107,  66, 117, 102, 
    102, 101, 114,  68,  97, 116, 
     97,   0,  67, 111, 108, 111, 
    114,   0, 102, 108, 111,  97, 
    116,  51,   0, 171, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  54,   2,   0,   0, 
     80,  97, 100, 100, 105, 110, 
    103,   0,   0,   0,   3,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 195,   1, 
      0,   0,  48,   2,   0,   0, 
     64,   2,   0,   0,   0,   0, 
      0,   0, 100,   2,   0,   0, 
    108,   2,   0,   0,  12,   0, 
      0,   0,   5,   0,   0,   0, 
      1,   0,   4,   0,   0,   0, 
      2,   0, 144,   2,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  33,   2, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  54,  46,  51,  46,  57, 
     54,  48,  48,  46,  49,  54, 
     51,  56,  52,   0, 171, 171, 
     73,  83,  71,  78,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  79,  83, 
     71,  78,   8,   0,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  83,  72,  69,  88, 
     40,   1,   0,   0,  80,   0, 
      5,   0,  74,   0,   0,   0, 
    106,   8,   0,   1,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0, 158,   0, 
      0,   4,   0, 224,  17,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,  95,   0,   0,   2, 
    114,   0,   2,   0, 104,   0, 
      0,   2,   2,   0,   0,   0, 
    155,   0,   0,   4,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,   0,   0,  35,   0, 
      0,   8,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
      2,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  10,   0,   2,   0, 
    167,   0,   0, 139,   2, 131, 
      0, 128, 131, 153,  25,   0, 
    226,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 233,  17,   0,   0,   0, 
      0,   0,  45,   0,   0, 136, 
    194,   0,   0, 128,  67,  85, 
     21,   0, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,  10, 
      2,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10, 226,   0,  16,   0, 
      0,   0,   0,   0,   6, 128, 
     32,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   6,   9, 
     16,   0,   1,   0,   0,   0, 
     86,  14,  16,   0,   0,   0, 
      0,   0, 168,   0,   0,   9, 
    114, 224,  17,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
    150,   7,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     83,  84,  65,  84, 148,   0, 
      0,   0,   6,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0
};