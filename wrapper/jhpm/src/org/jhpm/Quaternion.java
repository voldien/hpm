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
 * Quaternion class responsible for
 * representing a 3D orientation with
 * help of a 4D vector.
 *
 * @author Valdemar Lindberg
 */
public class Quaternion {

    private float e[];

    /**
     * Default constructor.
     */
    public Quaternion() {
        e = new float[4];
    }

    /**
     * Create instance by setting
     * each elements individually.
     * @param w
     * @param x
     * @param y
     * @param z
     */
    public Quaternion(float w, float x, float y, float z) {
        e = new float[4];
        set(w, x, y, z);
    }

    /**
     * Create Quaternion looking at position.
     *
     * @param target
     * @param up
     * @return
     */
    public static native Quaternion lookRotation(Vector3 target, Vector3 up);

    /**
     * @param target
     * @param up
     * @return
     */
    public static native Quaternion lookAt(Vector3 target, Vector3 up);

    /**
     * Create quaternion from axis.
     *
     * @param pitch
     * @param yaw
     * @param roll
     * @return
     */
    public static native Quaternion createQuaternionOfAxis(float pitch, float yaw,
                                                           float roll);

    /**
     * Create quaternion from Eular axis.
     *
     * @param axis eular axis object.
     * @return rotated quaternion.
     */
    public static native Quaternion createQuaternionOfAxis(Vector3 axis);

    /**
     * Create quaternion from rotation around axis.
     *
     * @param axis
     * @param angle
     * @return
     */
    public static native Quaternion createFromAxisAngle(Vector3 axis, float angle);

    /**
     * Create quaternion from direction vector.
     *
     * @param direction direction.
     * @return normalized quaternion.
     */
    public static native Quaternion createQuaternionOfDirection(Vector3 direction);

    /**
     * Create linear interpolate quaternion
     * from two points.
     *
     * @param from  starting point.
     * @param to    end point.
     * @param speed [0,1]
     * @return interpolated quaternion.
     */
    public static native Quaternion lerp(Quaternion from, Quaternion to,
                                         float speed);

    /**
     * Create spherical interpolate quaternion
     * from two points.
     *
     * @param from  starting point.
     * @param to    end point.
     * @param speed [0,1]
     * @return interpolated quaternion.
     */
    public static native Quaternion slerp(Quaternion from, Quaternion to,
                                          float speed);

    /**
     * Create identity quaternion.
     *
     * @return none null quaternion if successfully.
     */
    public static native Quaternion identity();

    /**
     * Get individual X component.
     */
    public float x() {
        return e[1];
    }

    /**
     * Get individual Y component.
     *
     * @return
     */
    public float y() {
        return e[2];
    }

    /**
     * Get individual Z component.
     *
     * @return
     */
    public float z() {
        return e[3];
    }

    /**
     * Get individual W component.
     *
     * @return
     */
    public float w() {
        return e[1];
    }

    /**
     * Set individual W component.
     */
    public void setW(float w) {
        e[0] = w;
    }

    /**
     * Set individual X component.
     */
    public void setX(float x) {
        e[1] = x;
    }

    /**
     * Set individual Y component.
     */
    public void setY(float y) {
        e[2] = y;
    }

    /**
     * Set individual Z component.
     */
    public void setZ(float z) {
        e[3] = z;
    }

    /**
     * Set the individual components in a single
     * method call.
     *
     * @param w w component, {aka* imaginary}.
     * @param x x component, real number.
     * @param y y component, real number.
     * @param z z component, real number.
     */
    public native void set(float w, float x, float y, float z);

    /**
     * Get up vector of quaternion.
     *
     * @return
     */
    public native Vector3 up();

    /**
     * Get forward vector of
     * quaternion.
     *
     * @return
     */
    public native Vector3 forward();

    /**
     * Get direction vector from vector
     * direction.
     *
     * @param unitDirect
     * @return direction in respect to unitDirect vector.
     */
    public native Vector3 getVector(Vector3 unitDirect);

    /**
     * Compute the magnitude.
     *
     * @return non-negative number.
     */
    public native float magnitude();

    /**
     * Compute the magnitude squared.
     *
     * @return non-negative number.
     */
    public native float magnitudeSquared();

    /**
     * Compute dot product from two quaternion.
     *
     * @param lh
     * @param rh
     * @return dot product between.
     */
    public native float dot(Quaternion lh, Quaternion rh);

    /**
     * Normalize quaternion.
     */
    public native void makeUnitQuaternion();

    /**
     * Compute normalized quaternion.
     *
     * @return normalized copy.
     */
    public native Quaternion normalize();

    /**
     * Create conjugate quaternion from
     * this quaternion.
     *
     * @return conjugated quaternion.
     */
    public native Quaternion conjugate();

    /**
     * Compute inverse of quaternion.
     * a^-1 = (~a) /
     *
     * @return inverse quaternion.
     */
    public native Quaternion inverse();

    /**
     * Convert quaternion to matrix4x4.
     *
     * @return non-null object.
     */
    public native Matrix4x4 getMatrix4x4();

    /**
     * Convert quaternion to matrix3x3.
     * @return non-null object.
     */
    public native Matrix3x3 getMatrix3x3();

    /**
     * Get individual element from
     * object.
     *
     * @return value of component.
     */
    public native float get(int index);

    /**
     * Add quaternion with another quaternion
     * component wise.
     *
     * @param q
     * @return
     */
    public native Quaternion add(Quaternion q);

    /**
     * Subtract quaternion with another quaternion
     * component wise.
     *
     * @param q
     * @return
     */
    public native Quaternion sub(Quaternion q);

    /**
     * Multiply quaternion with quaternion.
     *
     * @param q
     * @return quaternion product.
     */
    public native Quaternion mul(Quaternion q);

    /**
     * Multiply quaternion with vector.
     *
     * @param v
     * @return quaternion product.
     */
    public native Quaternion mul(Vector3 v);

    /**
     * Multiply quaternion with scalar.
     *
     * @param scalar
     * @return quaternion product.
     */
    public native Quaternion mul(float scalar);

    /**
     * Create clone object.
     *
     * @return non-null quaternion object with same
     * value for each components.
     */
    @Override
    protected native Object clone();

    /**
     * Perform equality compare if object equal
     *
     * @return true if object is equal per component,
     * otherwise false.
     */
    @Override
    public native boolean equals(Object obj);

    /**
     * Compute the hash of quaternion object.
     *
     * @Return hash code.
     */
    @Override
    public int hashCode() {
        return Objects.hash(Arrays.hashCode(e));
    }

    /**
     * Create string representation.
     *
     * @return non-null terminated string.
     */
    @Override
    public native String toString();

    /**
     * Get x axis angle.
     *
     * @return angle in radius.
     */
    public native float getPitch();

    /**
     * Get y axis angle.
     *
     * @return angle in radius.
     */
    public native float getYaw();

    /**
     * Get z axis angle.
     *
     * @return angle in radius.
     */
    public native float getRoll();

}
