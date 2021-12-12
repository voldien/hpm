using HpmSharp.HpmBinding;
using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace HpmSharp
{
	[StructLayout(LayoutKind.Sequential, Pack=16, Size=16)]
	public unsafe struct Vector4 : IEquatable<Vector4>, IFormattable
	{
		private float X;
		private float Y;
		private float Z;
		private float W;
		public Vector4(float val)
		{
			//  e = new System.Numerics.Vector4();
			X = val;
			Y = val;
			Z = val;
			W = val;
			set(val, val, val, val);
		}
		public Vector4(float x, float y, float z, float w)
		{
			//  e = new System.Numerics.Vector4();
			X = x;
			Y = y;
			Z = y;
			W = w;
			set(x, y, z, w);
		}

		public Vector4(float* x){
			// fixed(float* p = &X){
			// 	HpmNative.hpm_vec4_copyfv(p, x);
			// }
			X = x[0];
			Y = x[1];
			Z = x[2];
			W = x[3];
		}

		public static Vector4 unitVector(Vector4 v)
		{
			return new Vector4();
			//return HpmNative.
		}

		public string ToString(string format, IFormatProvider formatProvider)
		{
			unsafe
			{
				fixed(float* p = &this.X){
					HpmNative.hpm_vec4_sprint(format, p);
				}
			}
			return format;
		}

		public bool Equals(Vector4 other)
		{
			fixed (float* p = &this.X)
			{
				return HpmNative.hpm_vec4_eqfv(p, &other.X);
			}
		}

	// 	public static native Vector4 minVec(final Vector4 v1, final Vector4 v2);

		/**
		* Compute the max vector by component.
		*
		* @param v1
		* @param v2
		* @return
		*/
		// public static Vector4 maxVec(final Vector4 v1, final Vector4 v2){

		// }

		/**
		* Compute dot product between v1 and v2
		*
		* @param v1 valid vector4.
		* @param v2 valid vector4.
		* @return inner dot product between v1 and v2.
		*/
		public static float dot(Vector4 v1, Vector4 v2){
			return HpmNative.hpm_vec4_dotfv(&v1.X, &v2.X);
		}

		/**
		* @return Get component x of vector.
		*/
		public float x
		{
			get { return X; }
			set { X = value; }
		}

		/**
		* @return Get component x of vector.
		*/
		public float y
		{
			get { return Y; }
			set { Y = value; }
		}

		/**
		* @return Get component x of vector.
		*/
		public float z
		{
			get { return Z; }
			set { Z = value; }
		}

		/**
		* @return Get component x of vector.
		*/
		public float w
		{
			get { return W; }
			set { W = value; }
		}
		/**
		* Set each elements individually.
		*
		* @param x element component.
		* @param y element component.
		* @param z element component.
		* @param w element component.
		*/
		public void set(float x, float y, float z, float w){

		}

		/**
		* Get component by index.
		*/
		// public float this[int i]
		// {
		// 	get => 0;//*(&X[i]);
		// 	set => *(&X[i]) = value;
		// }

		/**
		* Negate vector.
		*
		* @return negate copy.
		*/
		public Vector4 negate(){
			return new Vector4();
		}

		/**
		* Compute length of vector.
		*
		* @return non-negative number.
		*/
		public float length(){


			fixed(float* p = &X){
				return HpmNative.hpm_vec4_lengthfv(p);
			}
		}

		/**
		* Compute length in square.
		*
		* @return non-negative number.
		*/
		public float squaredLength(){
			fixed (float* p = &X)
			{
				return HpmNative.hpm_vec4_lengthsqurefv(p);
			}
		}

		/**
		* Normalize current vector.
		*/
		public void makeUnitVector(){
			fixed(float* p = &X){
				HpmNative.hpm_vec4_normalizefv(p);
			}
		}

		/**
		* @return
		*/
		public float minComponent(){
			return 0;
		}

		/**
		* @return
		*/
		public float maxComponent(){
			return 0;
		}

		/**
		* @return
		*/
		public float maxAbsComponent(){
			return 0;
		}

		/**
		* @return
		*/
		public float minAbsComponent(){
			return 0;
		}

		/**
		* @return
		*/
		public int indexOfMinComponent(){
			return 0;
		}

		/**
		* @return
		*/
		public int indexOfMaxComponent(){
			return 0;
		}

		/**
		* @return
		*/
		public int indexOfMinAbsComponent(){
			return 0;
		}

		/**
		* @return
		*/
		public int indexOfMaxAbsComponent(){
			return 0;
		}

		/**
		* Compute normalized vector.
		*
		* @return normalize copy.
		*/
		public Vector4 normalize(){
			Vector4 v = this;
			HpmNative.hpm_vec4_normalizefv(&v.X);
			return v;
		}

		/**
		* Addition of vector by each elements
		* individually.
		*
		* @param v1 valid vector.
		* @return addition vector.
		*/
		public static Vector4 operator+(Vector4 v1, Vector4 v2){
			return new Vector4();
		}

		/**
		* Subtract
		*
		* @param v1 valid vector.
		* @return
		*/
		public static Vector4 operator-(Vector4 v1, Vector4 v2){
			return new Vector4();
		}

		/**
		* Divide vector by each element by each component
		* component wise.
		*
		* @param v1 valid vector.
		* @return divided vector.
		*/
		public static Vector4 operator/(Vector4 v1, Vector4 v2){
			return new Vector4();
		}
		/**
		* @param f1 scalar.
		* @return divided vector.
		*/
		public static Vector4 operator/(Vector4 v1, float v2){
			return new Vector4();
		}

		/**
		* Multiple vector by a vector.
		*
		* @param f1
		* @return product vector.
		*/
		public static Vector4 operator*(Vector4 v1, Vector4 v2){
			return new Vector4();
		}

		/**
		* Multiple vector by a scalar.
		*
		* @param f1
		* @return product vector.
		*/
		public static Vector4 operator*(Vector4 v1, float v2){
			return new Vector4();
		}

		// public static float* operator&&(Vector4 vector){
		// 	return &vector.X;
		// }

	}

}
