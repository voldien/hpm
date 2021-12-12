
using System;
using System.Runtime.InteropServices;
using NativeLibraryLoader;

#pragma warning disable CS1591

namespace HpmSharp.HpmBinding
{
	public static unsafe partial class HpmNative
	{
		private static readonly NativeLibrary m_hpmlibrary;

		private static NativeLibrary LoadHpm()
		{
            string[] names;

            if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
            {
                names = new[]
                {
                    "hpm.dll",
                };
            }
            else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
            {
                names = new[]
                {
                    "libhpm.so",
                    "libhpm.so.1"
                };
            }
            else if (RuntimeInformation.IsOSPlatform(OSPlatform.OSX))
            {
                names = new[]
                {
                    "libhpm.dylib",
                };
            }
            else
            {
                names = new []{""};
            }

            NativeLibrary lib = new NativeLibrary(names);
            return lib;
		}

        private static T LoadFunction<T>(string name)
        {
            return m_hpmlibrary.LoadFunction<T>(name);
        }

		static HpmNative()
		{
			m_hpmlibrary = LoadHpm();
			LoadOpenHpm();
		}
	}
}
