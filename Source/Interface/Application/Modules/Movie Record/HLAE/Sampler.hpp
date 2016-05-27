#pragma once

/*
	The files in this directory are modified, originally by Dominik 'ripieces' Tugend from HLAE
	See Readme

	https://github.com/ripieces/advancedfx
	https://github.com/ripieces/advancedfx/blob/master/resources/readme.txt
*/

namespace SDR
{
	namespace Sampler
	{
		class __declspec(novtable) IFramePrinter abstract
		{
		public:
			virtual void Print(unsigned char* data) abstract = 0;
		};

		class __declspec(novtable) ISampleFns abstract
		{
		public:
			/// <summary>frame += sample</summary>
			virtual void Fn_1(void const *sample) abstract = 0;

			/// <summary>frame += w * sample </summary>
			virtual void Fn_2(void const *sample, float w) abstract = 0;

			/// <summary>frame += w * (sampleA + sampleB)</summary>
			virtual void Fn_4(void const *sampleA, void const *sampleB, float w) abstract = 0;
		};

		// EasySamplerBase /////////////////////////////////////////////////////////////

		/// <summary>
		///   Base class, not intended to be used directly.
		///   This class supplies implementation of fundamental sampling logic.
		/// </summary>
		class EasySamplerBase abstract
		{
		public:

		protected:
			/// <param name="exposure">time the shutter is kept open measured in number of frames</param>
			EasySamplerBase(
				double frameDuration,
				double startTime,
				double exposure);

			bool CanSkipConstant(double time, double durationPerSample, int numPreviousSamplesRequired);

			/// <summary>
			///   Triggers the sampling logic for an example. If there is anything to be sampled
			///   SubSample will be called one or more times.
			/// </summary>
			void Sample(double time);

			/// <summary>
			///   Can be called mutliple times by Sample(double).<br />
			///   The calle is supposed to approximate a sub-integral
			///   between two samples, using the information supplied.
			/// </summary>
			/// <param name="timeA">Time of last sample.</param>
			/// <param name="timeB">Time of current sample.</param>
			/// <param name="subTimeA">lower integral boundary</param>
			/// <param name="subTimeB">upper integral boundary</param>
			/// <remarks>timeA &lt;= subTimeA &lt; subTimeB &lt;=timeB</remarks>
			virtual void SubSample(
				double timeA,
				double timeB,
				double subTimeA,
				double subTimeB) abstract = 0;

			/// <summary>
			///   Can be called mutliple times by Sample(double).<br />
			///   The calle is supposed to finish (print + clear)
			///   the current frame.
			/// </summary>
			virtual void MakeFrame() abstract = 0;

		protected:
			/// <summary>
			///	  Auto 2 (trapezium) / 1 (rectangle) / 0 point sampling by integration.<br />
			///   Selects, optimizes and combines the integration using a given set of base functions.
			/// </summary>
			/// <param name="sampleA">can be 0</param>
			/// <param name="sampleB">can be 0</param>
			static void Integrator_Fn(ISampleFns *fns, void const *sampleA, void const *sampleB, double timeA, double timeB, double subTimeA, double subTimeB);

		private:
			double m_FrameDuration;
			double m_LastFrameTime;
			double m_LastSampleTime;
			bool m_ShutterOpen;
			double m_ShutterOpenDuration;
			double m_ShutterTime;
		};


		// EasySamplerSettings /////////////////////////////////////////////////////////

		/// <summary>
		///   Encapsulates common sampler settings.
		/// </summary>
		class EasySamplerSettings
		{
		public:
			enum Method
			{
				ESM_Rectangle,
				ESM_Trapezoid
			};

			EasySamplerSettings(
				int width,
				int height,
				Method method,
				double frameDuration,
				double startTime,
				double exposure,
				float frameStrength
			);

			EasySamplerSettings(EasySamplerSettings const & settings);

			double Exposure_get() const;
			double FrameDuration_get() const;
			float FrameStrength_get() const;
			int Height_get() const;
			Method Method_get() const;
			double StartTime_get() const;
			int Width_get() const;

		private:
			double m_Exposure;
			double m_FrameDuration;
			float m_FrameStrength;
			int m_Height;
			Method m_Method;
			double m_StartTime;
			int m_Width;
		};


		// EasyByteSampler /////////////////////////////////////////////////////////////

		class EasyByteSampler : public EasySamplerBase,
			private ISampleFns
		{
		public:


			/// <param name="pitch">bytes of memory to skip for a row</param>
			EasyByteSampler(
				EasySamplerSettings const & settings,
				int pitch,
				IFramePrinter * framePrinter
			);

			~EasyByteSampler();

			bool CanSkipConstant(double time, double durationPerSample);

			///	<param name="data">NULLPTR is interpreted as the ideal shutter being closed for the deltaTime that passed.</param>
			/// <remarks>A closed shutter and a weight of 0 are not the same, because the integral can be different (depends on the method).</remarks>
			void Sample(unsigned char const * data, double time);

		protected:
			virtual void EasySamplerBase::MakeFrame()
			{
				PrintFrame();
				ClearFrame(m_Settings.FrameStrength_get());
			}

			virtual void EasySamplerBase::SubSample(
				double timeA,
				double timeB,
				double subTimeA,
				double subTimeB)
			{
				Integrator_Fn(this,
							  m_HasLastSample ? m_LastSample.get() : 0, m_CurSample,
							  timeA, timeB, subTimeA, subTimeB
				);
			}

		private:

			class Frame
			{
			public:
				Frame(size_t length)
				{
					Data = std::make_unique<float[]>(length);
					WhitePoint = 0;

					memset(Data.get(), 0, sizeof(float) * length);
				}

				std::unique_ptr<float[]> Data;
				float WhitePoint;
			};

			unsigned char const * m_CurSample;
			EasySamplerSettings m_Settings;
			Frame m_Frame;
			IFramePrinter * m_FramePrinter;
			bool m_HasLastSample;
			std::unique_ptr<unsigned char[]> m_LastSample;
			std::unique_ptr<unsigned char[]> m_PrintMem;
			int m_Pitch;

			void ClearFrame(float frameStrength);

			/// <summary>Implements ISampleFns.</summary>
			virtual void Fn_1(void const * sample);

			/// <summary>Implements ISampleFns.</summary>
			virtual void Fn_2(void const * sample, float w);

			/// <summary>Implements ISampleFns.</summary>
			virtual void Fn_4(void const * sampleA, void const * sampleB, float w);

			void PrintFrame();

			void ScaleFrame(float factor);
		};
	}
}
