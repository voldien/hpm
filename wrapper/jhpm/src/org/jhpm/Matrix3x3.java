/**
 * High performance matrix library wrapper, utilizing SIMD extensions.
 * Copyright (C) 2017  Valdemar Lindberg
 * <p>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * <p>
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * <p>
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package org.jhpm;

import java.util.Arrays;
import java.util.Objects;

/**
 * Matrix3x3, contains three rows for which
 * each contains four elements.
 *
 * @author Valdemar Lindberg
 */
public class Matrix3x3 {

    private float[] e;

    public Matrix3x3() {
        e = new float[16];
    }

    /**
     * Calculate the determinant.
     *
     * @return determinant.
     */
    public native float determinant();

    /**
     * Compute the inverse matrix.
     * @return inverse matrix.
     */
    public native Matrix3x3 inverse();

    /**
     * Determine of an identity matrix.
     * @return true if identity, false otherwise.
     */
    public native boolean isIdentity();

    /**
     * Make current object to identity
     * matrix.
     */
    public native void identity();

    /**
     * Transpose matrix.
     * @return copy matrix, transposed.
     */
    public native Matrix3x3 transpose();

    /**
     * Get nth coloum of matrix.
     * @param index
     * @return
     */
    public native Vector3 get(int index);

    /**
     * Get elements in array.
     * @param i nth coloum index.
     * @param j nth row index.
     * @return
     */
    public native float get(int i, int j);

    /**
     * @param v1
     * @return
     */
    public native Matrix3x3 add(Matrix3x3 v1);

    /**
     * @param v1
     * @return
     */
    public native Matrix4x4 sub(Matrix3x3 v1);

    /**
     * @param f1
     * @return
     */
    public native Matrix3x3 mul(Matrix3x3 f1);

    /**
     * @param f1
     * @return
     */
    public native Vector3 mul(final Vector3 f1);

    /**
     * Determine if matrices are identical.
     * @return true if identical, false otherwise.
     */
    @Override
    public native boolean equals(Object obj);

    /**
     * @return hash code representing the vector elements.
     */
    @Override
    public int hashCode() {
        return Objects.hash(Arrays.hashCode(e));
    }

    /**
     * Clone object
     * @return
     */
    @Override
    protected native Object clone();

    /**
     * Create string representation of the
     * matrix.
     * @return non-null terminated string.
     */
    @Override
    public native String toString();

}
