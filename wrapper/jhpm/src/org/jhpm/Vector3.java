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
 * @author Valdemar Lindberg
 */
public class Vector3 {

    private float[] e;

    /**
     * Create default vector3 object
     * instance.
     */
    Vector3() {
        e = new float[4];
    }

    /**
     * Set aligned vector value.
     *
     * @param val aligned vector value.
     */
    Vector3(float val) {
        e = new float[3];
        setX(val);
        setY(val);
        setZ(val);
    }

    /**
     * @param e0
     * @param e1
     * @param e2
     */
    Vector3(float e0, float e1, float e2) {
        set(e0, e1, e2);
    }

    /**
     * Compute unit vector.
     * @param v
     * @return normalized vector.
     */
    public native static Vector3 unitVector3(final Vector3 v);

    /**
     * Compute the minimum component pair wise
     * with vector v1 and v2.
     * @param v1
     * @param v2
     * @return vector with minimum value for each component.
     */
    public native static Vector3 minVec(final Vector3 v1, final Vector3 v2);

    /**
     * @param v1
     * @param v2
     * @return
     */
    public native static Vector3 maxVec(final Vector3 v1, final Vector3 v2);

    /**
     * Compute the cross product of vector v1 and v2.
     * Where the order of vector will yield different
     * result.
     * @param v1
     * @param v2
     * @return cross product vector.
     */
    public native static Vector3 cross(final Vector3 v1, final Vector3 v2);

    /**
     * Compute the reflection vector.
     * @param v1 incoming vector.
     * @param normal normalized vector.
     * @return reflection vector.
     */
    public native static Vector3 reflection(final Vector3 v1, final Vector3 normal);

    /**
     * Compute the refraction vector.
     * @param v1 incoming vector.
     * @param normal normalized vector.
     * @param index refraction index.
     * @return refraction vector.
     */
    public native static Vector3 refraction(final Vector3 v1, final Vector3 normal, float index);

    /**
     * Compute the dot product of vector v1 and v2.
     * @param v1
     * @param v2
     * @return the angle between v1 and v2 time the length of v1 and v2.
     */
    public native static float dot(final Vector3 v1, final Vector3 v2);

    /**
     * Comput the triple product (v1 x v2) * v3
     * @param v1
     * @param v2
     * @param v3
     * @return
     */
    public native static float tripleProduct(final Vector3 v1, final Vector3 v2, final Vector3 v3);

    /**
     * Compute the tangent vector.
     * @param normal
     * @return
     */
    public native static Vector3 tangent(final Vector3 normal);

    /**
     * Compute the bi tangent vector.
     * @param normal
     * @param tangent
     * @return
     */
    public native static Vector3 biTangent(final Vector3 normal, final Vector3 tangent);

    /**
     * Compute the bi normal.
     * @param normal
     * @param tangent
     * @return
     */
    public native static Vector3 biNormal(final Vector3 normal, final Vector3 tangent);

    /**
     * Get normalized forward vector.
     * @return
     */
    public static Vector3 forward() {
        return new Vector3(0.0f, 0.0f, 1.0f);
    }

    /**
     *
     * @return
     */
    public static Vector3 back() {
        return new Vector3(0.0f, 0.0f, -1.0f);
    }

    /**
     *
     * @return
     */
    public static Vector3 right() {
        return new Vector3(1.0f, 0.0f, 0.0f);
    }

    /**
     *
     * @return
     */
    public static Vector3 left() {
        return new Vector3(-1.0f, 0.0f, 0.0f);
    }

    /**
     *
     * @return
     */
    public static Vector3 up() {
        return new Vector3(0.0f, 1.0f, 0.0f);
    }

    /**
     *
     * @return
     */
    public static Vector3 down() {
        return new Vector3(0.0f, -1.0f, 0.0f);
    }

    /**
     *
     * @return
     */
    public static Vector3 zero() {
        return new Vector3(0.0f, 0.0f, 0.0f);
    }

    /**
     * Linear interpolation between v1 and v2 based on t.
     *
     * @return
     */
    public native static Vector3 lerp(Vector3 vec1, Vector3 vec2, float t);

    /**
     * Spherical interpolation.
     *
     * @return
     */
    public native static Vector3 slerp(Vector3 vec1, Vector3 vec2, float t);

    /**
     * Get X component of the vector.
     *
     * @return value of x.
     */
    public float x(){return this.e[0];}

    /**
     * Get Y component of the vector.
     *
     * @return value of y.
     */
    public float y(){return this.e[1];}

    /**
     * Get Z component of the vector.
     *
     * @return value of z.
     */
    public float z(){return this.e[2];}

    /**
     * Set x component of the vector.
     *
     * @param x
     */
    public void setX(float x){e[0] = x;}

    /**
     * Set y component of the vector.
     *
     * @param y
     */
    public void setY(float y){e[0] = y;}

    /**
     * Set Z component of the vector.
     *
     * @param z
     */
    public void setZ(float z){e[0] = z;}

    /**
     * Set all components of the vector.
     *
     * @param x component.
     * @param y component.
     * @param z component.
     */
    public native void set(float x, float y, float z);

    /**
     * Compute negated vector.
     *
     * @return negated vector.
     */
    public native Vector3 negate();

    /**
     * Get component by its index.
     * @param index nth element in the vector.
     * @return value of the component.
     */
    public native float get(int index);

    /**
     * Compute the length of the vector.
     *
     * @return non-negative number.
     */
    public native float length();

    /**
     * Compute length square of the vector.
     *
     * @return non-negative number.
     */
    public native float squaredLength();

    /**
     * Compute and set vector a normalized
     * vector.
     */
    public native void makeUnitVector();

    /**
     * @return
     */
    public native float minComponent();

    public native float maxComponent();

    public native float maxAbsComponent();

    public native float minAbsComponent();

    public native int indexOfMinComponent();

    public native int indexOfMaxComponent();

    public native int indexOfMinAbsComponent();

    public native int indexOfMaxAbsComponent();

    /**
     * @return
     */
    public native Vector3 normalize();

    /**
     * @return
     */
    public native Vector3 add(final Vector3 v1);

    /**
     *
     * @param v1
     * @return
     */
    public native Vector3 sub(final Vector3 v1);

    /**
     *
     * @param v1
     * @return
     */
    public native Vector3 div(final Vector3 v1);

    /**
     *
     * @param f
     * @return
     */
    public native Vector3 div(final float f);

    /**
     *
     * @param v1
     * @return
     */
    public native Vector3 mul(final Vector3 v1);

    /**
     *
     * @param f
     * @return
     */
    public native Vector3 mul(final float f);

    /**
     * Compare if object equal.
     */
    @Override
    public native boolean equals(Object obj);

    /**
     *
     */
    @Override
    public int hashCode() {
        return Objects.hash(Arrays.hashCode(e));
    }

    /**
     * Create clone object.
     */
    @Override
    protected native Object clone();

    /**
     * Convert to readable string format.
     * @return non-null terminated string.
     */
    @Override
    public native String toString();
}
