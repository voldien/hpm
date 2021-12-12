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
 * Vector object with four elements,
 * x, y, z and w.
 *
 * @author Valdemar Lindberg
 */
public class Vector4 {

    private float e[];

    /**
     * Create default instance of the object.
     */
    public Vector4() {
        this.e = new float[4];
    }

    /**
     * Create instance with align elements values.
     *
     * @param val align value.
     */
    public Vector4(float val) {
        set(val, val, val, val);
    }

    /**
     * Create instance by setting each elements individually.
     *
     * @param x
     * @param y
     * @param z
     * @param w
     */
    public Vector4(float x, float y, float z, float w) {
        set(x, y, z, w);
    }

    /**
     * Create a normalize vector.
     *
     * @return normalized vector.
     */
    public static native Vector4 unitVector(Vector4 v);

    /**
     * Compute the min vector by component.
     *
     * @param v1
     * @param v2
     * @return
     */
    public static native Vector4 minVec(final Vector4 v1, final Vector4 v2);

    /**
     * Compute the max vector by component.
     *
     * @param v1
     * @param v2
     * @return
     */
    public static native Vector4 maxVec(final Vector4 v1, final Vector4 v2);

    /**
     * Compute dot product between v1 and v2
     *
     * @param v1 valid vector4.
     * @param v2 valid vector4.
     * @return inner dot product between v1 and v2.
     */
    public static native float dot(Vector4 v1, Vector4 v2);

    /**
     * @return Get component x of vector.
     */
    public float x() {
        return e[0];
    }

    /**
     * @return Get component x of vector.
     */
    public float y() {
        return e[1];
    }

    /**
     * @return Get component x of vector.
     */
    public float z() {
        return e[2];
    }

    /**
     * @return Get component x of vector.
     */
    public float w() {
        return e[3];
    }

    /**
     * @param x
     */
    public void setX(float x) {
        e[0] = x;
    }

    /**
     * @return Get component x of vector.
     */
    public void setY(float y) {
        e[1] = y;
    }

    /**
     * @return Get component x of vector.
     */
    public void setZ(float z) {
        e[0] = z;
    }

    /**
     * @return Get component x of vector.
     */
    public void setW(float w) {
        e[0] = w;
    }

    /**
     * Set each elements individually.
     *
     * @param x element component.
     * @param y element component.
     * @param z element component.
     * @param w element component.
     */
    public native void set(float x, float y, float z, float w);

    /**
     * Get component by index.
     */
    public native float get(int i);

    /**
     * Negate vector.
     *
     * @return negate copy.
     */
    public native Vector4 negate();

    /**
     * Compute length of vector.
     *
     * @return non-negative number.
     */
    public native float length();

    /**
     * Compute length in square.
     *
     * @return non-negative number.
     */
    public native float squaredLength();

    /**
     * Normalize current vector.
     */
    public native void makeUnitVector();

    /**
     * @return
     */
    public native float minComponent();

    /**
     * @return
     */
    public native float maxComponent();

    /**
     * @return
     */
    public native float maxAbsComponent();

    /**
     * @return
     */
    public native float minAbsComponent();

    /**
     * @return
     */
    public native int indexOfMinComponent();

    /**
     * @return
     */
    public native int indexOfMaxComponent();

    /**
     * @return
     */
    public native int indexOfMinAbsComponent();

    /**
     * @return
     */
    public native int indexOfMaxAbsComponent();

    /**
     * Compute normalized vector.
     *
     * @return normalize copy.
     */
    public native Vector4 normalize();

    /**
     * Addition of vector by each elements
     * individually.
     *
     * @param v1 valid vector.
     * @return addition vector.
     */
    public native Vector4 add(final Vector4 v1);

    /**
     * Subtract
     *
     * @param v1 valid vector.
     * @return
     */
    public native Vector4 sub(final Vector4 v1);

    /**
     * Divide vector by each element by each component
     * component wise.
     *
     * @param v1 valid vector.
     * @return divided vector.
     */
    public native Vector4 div(final Vector4 v1);

    /**
     * @param f1 scalar.
     * @return divided vector.
     */
    public native Vector4 div(final float f1);

    /**
     * Multiple vector by a vector.
     *
     * @param f1
     * @return product vector.
     */
    public native Vector4 mul(final Vector4 f1);

    /**
     * Multiple vector by a scalar.
     *
     * @param f1
     * @return product vector.
     */
    public native Vector4 mul(final float f1);

    /**
     * Compare if object is equal.
     *
     * @param obj non-null object.
     * @return true if equal.
     */
    @Override
    public native boolean equals(Object obj);

    /**
     * Compute hash code representing
     * the vector elements.
     *
     * @return hash code representing the vector elements.
     */
    @Override
    public int hashCode() {
        return Objects.hash(Arrays.hashCode(e));
    }

    /**
     * Convert to readable string format.
     *
     * @return non-null terminated string.
     */
    @Override
    public native String toString();

    /**
     * Create clone object.
     *
     * @return non-null object.
     */
    @Override
    protected native Object clone();

}
