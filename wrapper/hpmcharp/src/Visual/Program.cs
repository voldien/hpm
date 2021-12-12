using System;
using System.IO;
using System.Numerics;
using Veldrid;
//using Veldrid.Sdl2;
using Veldrid.StartupUtilities;
using HpmSharp;
using System.Text;

namespace HpmSharpVisual
{
	class Program
	{
		static void Main(string[] args)
		{
			Hpm.init(SIMD.HPM_DEFAULT);


			System.Numerics.Matrix4x4 pp;
			HpmSharp.Matrix4x4 m = new HpmSharp.Matrix4x4();

			HpmSharp.Matrix4x4 _v = HpmSharp.Matrix4x4.identity();
			float x = m.determinant();

			Console.WriteLine(m.ToString());
			HpmSharp.Vector4 vv = new HpmSharp.Vector4();
			float x_x = vv.length();

			Console.Write(x);

			// 		#if DEBUG
			// 					const bool debug = true;
			// 		#else
			// 					const bool debug = false;
			// #endif
			// 			bool fullscreen = false;
			// 			var graphicsDeviceOptions = new GraphicsDeviceOptions(debug, null, true, ResourceBindingModel.Improved)
			// 			{
			// 				SwapchainSrgbFormat = false,
			// 				PreferStandardClipSpaceYDirection = true,
			// 				PreferDepthRangeZeroToOne = true
			// 			};

			// 			var windowState = fullscreen ? WindowState.BorderlessFullScreen : WindowState.Normal;

			// 			// Get display scale for primary monitor.
			// 			// TODO: Track moving window to a different display,
			// 			// which may change the scale.
			// 			//WindowScale = Sdl2Interop.GetDisplayScale(0);

			// 			var windowCreateInfo = new WindowCreateInfo(
			// 				(int)(WindowScale * x),
			// 				(int)(WindowScale * y),
			// 				(int)(WindowScale * width),
			// 				(int)(WindowScale * height),
			// 				windowState,
			// 				title);

			// 			var backend = preferredBackend ?? VeldridStartup.GetPlatformDefaultBackend();

			// 			VeldridStartup.CreateWindowAndGraphicsDevice(
			// 				windowCreateInfo,
			// 				graphicsDeviceOptions,
			// 				backend,
			// 				out _window,
			// 				out var graphicsDevice);


		}
	}
}
