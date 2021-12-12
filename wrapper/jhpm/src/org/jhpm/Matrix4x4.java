/**
    High performance matrix library wrapper, utilizing SIMD extensions.
    Copyright (C) 2017  Valdemar Lindberg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
package org.jhpm;

import java.util.Arrays;
import java.util.Objects;

/**
 * Matrix4x4, contains four rows for which
 * each contains four elements.
 *
 * @author Valdemar Lindberg
 */
public class Matrix4x4 {

    private float[] e;

    /**
     * Create default instance.
     */
    public Matrix4x4() {
        this.e = new float[16];
    }

    /**
     * Create translation matrix.
     *
     * @param x position in X axis.
     * @param y position in Y axis.
     * @param z position in Z axis.
     * @return Translation matrix.
     */
    public native static Matrix4x4 translate(float x, float y, float z);

    /**
     * Create translation matrix.
     *
     * @return translated matrix.
     */
    public native static Matrix4x4 translate(Vector3 translation);

    /**
     * Create rotation matrix from angle around the axis.
     *
     * @return rotation matrix.
     */
    public native static Matrix4x4 rotate(float angle, Vector3 axis);

    /**
     * Create rotation matrix from quaternion.
     *
     * @return rotation matrix.
     */
    public static native Matrix4x4 rotate(Quaternion quat);

    /**
     * Create scale matrix.
     *
     * @return scale matrix.
     */
    public native static Matrix4x4 scale(float x, float y, float z);

    /**
     * Create scale matrix.
     *
     * @param scale
     * @return scale matrix.
     */
    public native static Matrix4x4 scale(Vector3 scale);

    /**
     * Create perspective matrix.
     *
     * @param fov    angle in radius
     * @param aspect image view ratio.
     * @param near   distance from origin to start plane.
     * @param far    distance to the end plane.
     * @return perspective matrix.
     */
    public native static Matrix4x4 perspective(float fov, float aspect, float near,
                                               float far);

    /**
     * Create look at orientation translated
     * matrix.
     *
     * @param lookPosition camera eye look at position.
     * @param position     transformation in world space.
     * @param up
     * @return look at transformation matrix.
     */
    public native static Matrix4x4 lookAt(Vector3 lookPosition,
                                          Vector3 position, Vector3 up);

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
    public native static Matrix4x4 orth(float left, float right, float bottom, float top,
                                        float near, float far);

    /**
     * Create bias matrix.
     *
     * @return
     */
    public native static Matrix4x4 biasMatrix();

    /**
     * Create identity matrix.
     *
     * @return identity matrix.
     */
    public native static Matrix4x4 identity();

    /**
     * Check if matrix is an identity matrix.
     *
     * @return true if an identity matrix.
     */
    public native boolean isIdentity();

    /**
     * Compute determinant of the matrix.
     *
     * @return determine of the matrix.
     */
    public native float determinant();

    /**
     * Compute the inverse vector
     * if possible.
     *
     * @return inversed matrix.
     */
    public native Matrix4x4 inverse();

    /**
     * Transpose matrix.
     *
     * @return transposed matrix.
     */
    public native Matrix4x4 transpose();

    /**
     * Get vector4 element by index.
     *
     * @param index of nth column.
     * @return nth column.
     * @throws IndexOutOfBoundsException if index is either
     *                                   greater than 3 or less than 0.
     */
    public native Vector4 get(int index);

    /**
     * Get real value element by index.
     *
     * @param i non-negative number between 0 and 3.
     * @param j non-negative number between 0 and 3.
     * @return value at index.
     * @throws IndexOutOfBoundsException if index is either
     *                                   greater than 3 or less than 0.
     */
    public native float get(int i, int j);

    /**
     * Add matrix4x4 by each element from matrix4x4
     * v1.
     *
     * @param v1 valid matrix.
     * @return Added matrix.
     */
    public native Matrix4x4 add(final Matrix4x4 v1);

    /**
     * Subtract matrix4x4 by each element from
     * matrix4x4 v1.
     *
     * @param v1 valid matrix4x4.
     * @return subbed matrix.
     */
    public native Matrix4x4 sub(final Matrix4x4 v1);

    /**
     * Multiple matrix by another matrix.
     *
     * @param f1 matrix4x4.
     * @return product result.
     */
    public native Matrix4x4 mul(Matrix4x4 f1);

    /**
     * Multiple matrix by a scalar.
     *
     * @param f scalar.
     * @return product result.
     */
    public native Matrix4x4 mul(float f);

    /**
     * Multiple matrix by a 4 component vector.
     *
     * @param f1 vector4 object.
     * @return product result.
     */
    public native Vector4 mul(final Vector4 f1);

    /**
     * Create clone object of matrix4x4.
     *
     * @Return clone object.
     */
    @Override
    protected native Object clone();

    /**
     * Compare two matrices and check
     * if equal
     *
     * @Return true if object equal by each value.
     */
    @Override
    public native boolean equals(Object obj);

    /**
     * Compute the hash code.
     *
     * @Return true.
     */
    @Override
    public int hashCode() {
        return Objects.hash(Arrays.hashCode(e));
    }

    /**
     * Create string representation of the
     * matrix.
     *
     * @return non-null terminated string.
     */
    @Override
    public native String toString();

}
