using System;
using HpmSharp.HpmBinding;

namespace HpmSharp
{

	public static class Hpm
	{

		/// <summary>
		///
		/// </summary>
		/// <param name="code"></param>
		public static void init(SIMD code)
		{
			int status = HpmNative.hpm_init((uint) code);
			if (status == 0)
				throw new Exception("Bad");
			HpmNative.loadHpmInternalFunctions();
		}
	}
}
