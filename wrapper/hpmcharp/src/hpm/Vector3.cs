using System;
using System.Runtime.InteropServices;

namespace HpmSharp
{
	[StructLayout(LayoutKind.Sequential, Pack=0)]
	public unsafe struct Vector3 : IEquatable<Vector3>, IFormattable
	{

        private float X;
        private float Y;
        private float Z;
        private float _W;

		public bool Equals(Vector3 other)
		{
			throw new NotImplementedException();
		}

		public string ToString(string format, IFormatProvider formatProvider)
		{
			throw new NotImplementedException();
		}
	}
}
