using HpmSharp.HpmBinding;

namespace HpmSharp
{
	public unsafe static class MathUtil
	{
		public static Vector4 Max(Vector4 a, Vector4 b)
        {
			Vector4 c = new Vector4();
			//HpmNative.hpm_vec4_maxfv(&a.X, &b.X, &c.X);
			return c;
		}

		public static Vector4 Min(Vector4 a, Vector4 b)
        {
			Vector4 c = new Vector4();
			//HpmNative.hpm_vec4_minfv(&a, &b, &c);
			return c;
		}
    }
}
