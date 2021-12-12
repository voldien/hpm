using HpmSharp.HpmBinding;
using System;
using System.Runtime.InteropServices;
using System.Text;

namespace HpmSharp
{
	[StructLayout(LayoutKind.Sequential, Size=32, Pack=32)]
	public unsafe struct Matrix4x4 : IEquatable<Matrix4x4>, IFormattable
	{
		internal float m11, m21, m31, m41,    	/*  column1 */
			m12, m22, m32, m42,    				/*  column2 */
			m13, m23, m33, m43,    				/*  column3 */
			m14, m24, m34, m44;    				/*  column4 */


		public static unsafe Matrix4x4 operator *(Matrix4x4 a, Matrix4x4 b)
		{
			Matrix4x4 c = new Matrix4x4();
			HpmNative.hpm_mat4x4_multiply_mat4x4fv(&a.m11, &b.m11, &c.m11);
			return c;
		}

		public static bool operator ==(Matrix4x4 s1, Matrix4x4 s2) {
			//fixed(float* pa = &.s1.m11, pb = &s2.m11){
				return HpmNative.hpm_mat4_eqfv((float*)&s1, (float*)&s2);
			//}
		 }
		public static bool operator !=(Matrix4x4 s1, Matrix4x4 s2) {
				return HpmNative.hpm_mat4_neqfv((float*)&s1, (float*)&s2);
					}

		/**
		* Create translation matrix.
		*
		* @param x position in X axis.
		* @param y position in Y axis.
		* @param z position in Z axis.
		* @return Translation matrix.
		*/
		public static Matrix4x4 translate(float x, float y, float z)
		{
			Matrix4x4 matrix = new Matrix4x4();
			//fixed(float* pa = &matrix.m11){
			HpmNative.hpm_mat4x4_translationf(&matrix.m11, x, y, z);
			//}
			return matrix;
		}

		/**
		* Create translation matrix.
		*
		* @return translated matrix.
		*/
		public static Matrix4x4 translate(Vector3 translation)
		{
			Matrix4x4 matrix = new Matrix4x4();
			//fixed(float* pa = &matrix.m11){
			//HpmNative.hpm_mat4x4_translationfv(&matrix.m11, &translation);
			//}
			return matrix;
		}

		/**
		* Create rotation matrix from angle around the axis.
		*
		* @return rotation matrix.
		*/
		public static Matrix4x4 rotate(float angle, Vector3 axis)
		{
			return new Matrix4x4();
		}

		/**
		* Create rotation matrix from quaternion.
		*
		* @return rotation matrix.
		*/
		public static Matrix4x4 rotate(Quaternion quat)
		{
			return new Matrix4x4();
		}

		/**
		* Create scale matrix.
		*
		* @return scale matrix.
		*/
		public static Matrix4x4 scale(float x, float y, float z)
		{
			Matrix4x4 matrix = new Matrix4x4();
			//fixed(float* pa = &matrix.m11){
			HpmNative.hpm_mat4x4_scalef(&matrix.m11, x, y, z);
			//}
			return matrix;
		}

		/**
		* Create scale matrix.
		*
		* @param scale
		* @return scale matrix.
		*/
		public static Matrix4x4 scale(Vector3 scale)
		{
			Matrix4x4 matrix = new Matrix4x4();
			//fixed(float* pa = &matrix.m11){
			//HpmNative.hpm_mat4x4_scalefv(&matrix.m11, &scale);
			//}
			return matrix;
		}

		/**
		* Create perspective matrix.
		*
		* @param fov    angle in radius
		* @param aspect image view ratio.
		* @param near   distance from origin to start plane.
		* @param far    distance to the end plane.
		* @return perspective matrix.
		*/
		public static Matrix4x4 perspective(float fov, float aspect, float near,
												float far)
		{
			Matrix4x4 matrix = new Matrix4x4();
			//fixed(float* pa = &matrix.m11){
			HpmNative.hpm_mat4x4_projfv(&matrix.m11, fov,aspect, near, far);
			//}
			return matrix;
		}


		/**
		* Create look at orientation translated
		* matrix.
		*
		* @param lookPosition camera eye look at position.
		* @param position     transformation in world space.
		* @param up
		* @return look at transformation matrix.
		*/
		public static Matrix4x4 lookAt(Vector3 lookPosition,
											Vector3 position, Vector3 up)
		{
			return new Matrix4x4();
		}

		/**
		* Create orthographic perspective.
		*
		* @param left   left distance from box origin.
		* @param right  right distance from box origin.
		* @param bottom bottom distance from box origin.
		* @param top    top distance from box origin.
		* @param near   near distance from box origin.
		* @param far    far distance from box origin.
		* @return orthographic perspective matrix.
		*/
		public static Matrix4x4 orth(float left, float right, float bottom, float top,
											float near, float far)
		{
			Matrix4x4 matrix = new Matrix4x4();
			//fixed(float* pa = &matrix.m11){
			HpmNative.hpm_mat4x4_orthfv(&matrix.m11, left, right, bottom, top, near, far);
			//}
			return matrix;
		}

		/**
		* Create bias matrix.
		*
		* @return
		*/
		public static Matrix4x4 biasMatrix()
		{
			return new Matrix4x4();
		}

		/**
		* Create identity matrix.
		*
		* @return identity matrix.
		*/
		public static unsafe Matrix4x4 identity()
		{
			Matrix4x4 matrix = new Matrix4x4();
			HpmNative.hpm_mat4x4_identityfv((float*)&matrix);
			return matrix;
		}

		/**
		* Check if matrix is an identity matrix.
		*
		* @return true if an identity matrix.
		*/
		public bool isIdentity()
		{
			return false;
		}

		/**
		* Compute determinant of the matrix.
		*
		* @return determine of the matrix.
		*/
		public float determinant()
		{
			fixed(float* pa = &m11){
				return HpmNative.hpm_mat4x4_determinantfv(pa);
			}
		}

		/**
		* Compute the inverse vector
		* if possible.
		*
		* @return inversed matrix.
		*/
		public Matrix4x4 inverse()
		{
			Matrix4x4 matrix = new Matrix4x4();
			//fixed(float* pa = &matrix.m11){
			fixed (float* pa = &m11)
			{
				HpmNative.hpm_mat4x4_inversefv(pa, &matrix.m11);
			}
			//}
			return matrix;
		}

		/**
		* Transpose matrix.
		*
		* @return transposed matrix.
		*/
		public Matrix4x4 transpose()
		{
			Matrix4x4 matrix = new Matrix4x4();
			//fixed(float* pa = &matrix.m11){
			fixed(float* a = &m11){
				HpmNative.hpm_mat4x4_transposefv(a, &matrix.m11);
			}
			//}
			return matrix;
		}

		public bool Equals(Matrix4x4 other)
		{
			fixed(float* pa = &m11){
				return HpmNative.hpm_mat4_eqfv(pa, &other.m11);
			}
		}


		public override string ToString()
		{
			//char
			string text = new string("hello there some random message It hinkg");
			fixed(float* p = &m11){
				int count = HpmNative.hpm_vec4_sprint(text, p);
			}
			return text;
			//throw new NotImplementedException();
		}

		public string ToString(string format, IFormatProvider formatProvider)
		{
			throw new NotImplementedException();
		}

		/**
		* Get vector4 element by index.
		*
		* @param index of nth column.
		* @return nth column.
		* @throws IndexOutOfBoundsException if index is either
		*                                   greater than 3 or less than 0.
		*/
		//public Vector4 operator[]{ get {return null;}
		//}
		public Vector4 this[int i]
		{
			get { fixed (float* p = &m11) { return new Vector4(p); } }
		}

		/**
		* Get real value element by index.
		*
		* @param i non-negative number between 0 and 3.
		* @param j non-negative number between 0 and 3.
		* @return value at index.
		* @throws IndexOutOfBoundsException if index is either
		*                                   greater than 3 or less than 0.
		*/
		public float this[int x, int y]
		{
			get => 0;
			set => this.m11 = value;
		}


		/**
		* Add matrix4x4 by each element from matrix4x4
		* v1.
		*
		* @param v1 valid matrix.
		* @return Added matrix.
		*/
		public static Matrix4x4 operator +(Matrix4x4 v1, Matrix4x4 v2)
		{
			return new Matrix4x4();
		}

		/**
		* Subtract matrix4x4 by each element from
		* matrix4x4 v1.
		*
		* @param v1 valid matrix4x4.
		* @return subbed matrix.
		*/
		public static Matrix4x4 operator-( Matrix4x4 v1, Matrix4x4 v2)
		{
		return new Matrix4x4();
	}


		/**
		* Multiple matrix by a scalar.
		*
		* @param f scalar.
		* @return product result.
		*/
		public static Matrix4x4 operator+(Matrix4x4 a, float f1)
		{
			return new Matrix4x4();
		}

		/**
		* Multiple matrix by a 4 component vector.
		*
		* @param f1 vector4 object.
		* @return product result.
		*/
		public static Vector4 operator*(Matrix4x4 a, Vector4 f1)
		{
			Vector4 v = new Vector4();
			//HpmNative.hpm_mat4x4_multiply_mat1x4fv(&a.m11, &f1, &v);
			return v;
		}
	}
}
