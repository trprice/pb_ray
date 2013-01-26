/*
 *  Vector.h
 *  p_ray
 *
 *  Created by Taylor Price on 8/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef VECTOR_H
#define VECTOR_H

#include "assert.h"

/*
 * Vector class definition.
 */
class Vector {
    public:
        // Data Members
        //      These are public for several reasons, even though it's not
        //      good practice.
        //          1.) Ease of access
        //          2.) No overhead of function calls for accessors.
        float x, y, z;


        // Constructors
        Vector (float _x = 0.f, float _y = 0.f, float _z = 0.f)
                : x(_x), y(_y), z(_z)
        {
        }


        // Operators
        Vector operator+(const Vector &v) const {
            return Vector (x + v.x, y + v.y, z + v.z);
        }

        Vector& operator+=(const Vector &v) {
            x += v.x;
            y += v.y;
            z += v.z;

            return *this;
        }

        Vector operator-(const Vector &v) const {
            return Vector (x - v.x, y - v.y, z - v.z);
        }

        Vector& operator-=(const Vector &v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;

            return *this;
        }

        Vector operator*(float f) const {
            return Vector (f * x, f * y, f * z);
        }

        Vector& operator*=(float f) {
            x *= f;
            y *= f;
            z *= f;

            return *this;
        }

        Vector operator/(float f) const {
            assert (f != 0);
            float inverse =  1.f / f;
            return Vector (x * inverse, y * inverse, z * inverse);
        }

        Vector& operator/=(float f) {
            assert (f != 0);

            float inverse =  1.f / f;
            
            x *= inverse;
            y *= inverse;
            z *= inverse;

            return *this;
        }

        Vector operator-() const {
            return Vector (-x, -y, -z);
        }

        float operator[](int i) const {
            assert ((i >= 0) && (i <= 2));
            return (&x)[i];
        }

        float &operator[](int i) {
            assert ((i >= 0) && (i <= 2));
            return (&x)[i];
        }

};


/*
 * Vector inline non-member functions.
 */
inline float Dot (const Vector &v1, const Vector &v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

#endif
