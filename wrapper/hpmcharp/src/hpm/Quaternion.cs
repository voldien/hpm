using System;
using System.Runtime.InteropServices;

namespace HpmSharp
{
	[StructLayout(LayoutKind.Sequential, Pack=0)]
	public unsafe struct Quaternion : IEquatable<Quaternion>, IFormattable
	{
		private float x, y, z, w;

		public Quaternion(float pitch, float yaw, float roll){
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		public bool Equals(Quaternion other)
		{
			throw new NotImplementedException();
		}

		public string ToString(string format, IFormatProvider formatProvider)
		{
			throw new NotImplementedException();
		}
	}
}
