/*
 *  Geometry.h
 *  p_ray
 *
 *  Created by Taylor Price on 8/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "assert.h"
#include "math.h"

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

        
        // Member Functions
        float LengthSquared() const {
            return x*x + y*y + z*z;
        }

        float Length() const {
            return sqrtf (LengthSquared());
        }
};


/***************
 ***************
 * Inline Geometry Functions
 ***************
 ***************/

// Compute the dot product of two vectors.
inline float Dot (const Vector &v1, const Vector &v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}


// Compute the dot product of two vectors.
inline float AbsDot (const Vector &v1, const Vector &v2) {
    return fabsf (Dot (v1, v2));
}


////////////////////
// Function:
//      Cross
//
// Purpose:
//      Compute the cross product of two vectors.
//
// Parameters:
//      const Vector &v1
//      const Vector &v2
//
// Returns:
//      Returns a new vector.
////////////////////
inline Vector Cross (const Vector &v1, const Vector v2) {
    return Vector (((v1.y * v2.z) - (v1.z * v2.y)),
                   ((v1.z * v2.x) - (v1.x * v2.z)),
                   ((v1.x * v2.y) - (v1.y * v2.x))
                  );
}


////////////////////
// Function:
//      Normalize
//
// Purpose:
//      Compute the normalized version of a vector.
//
// Parameters:
//      Vector &v
//
// Return:
//      Returns a NEW vector that is the normalized
//      version of the input vector.
////////////////////
inline Vector Normalize (const Vector &v) {
    return v / v.Length();
}


////////////////////
// Function:
//      CoordinateSystem
//
// Purpose:
//      Generate a coordinate system from a given vector.
//
// Parameters:
//      Vector &v1 - The input vector from which the coordinate system will
//                   be generated.
//      Vector *v2 - The first generated perpendicular vector.
//      Vector *v3 - The second generated perpendicular vector.
//
// Return:
//      Nothing
////////////////////
inline void CoordinateSystem (const Vector &v1, Vector *v2, Vector *v3) {
    if (fabsf (v1.x) > fabsf (v1.y)) {
        float invLen = 1.f / sqrtf ((v1.x * v1.x) + (v1.z * v1.z));
        *v2 = Vector (-v1.z * invLen, 0.f, -v1.x * invLen);
    }
    else {
        float invLen = 1.f / sqrtf ((v1.y * v1.y) + (v1.z * v1.z));
        *v2 = Vector (0.f, -v1.z * invLen, -v1.y * invLen);
    }

    *v3 = Cross (v1, *v2);
}


////////////////////
// Class: Point
//
// Purpose:
//      Encapsulate the data for a point and make related functionality
//      available.
////////////////////
class Point {
    public:
        // Data Members
        //      These are public for several reasons, even though it's not
        //      good practice.
        //          1.) Ease of access
        //          2.) No overhead of function calls for accessors.
        float x, y, z;

        // Constructors
        Point (float _x = 0.f, float _y = 0.f, float _z = 0.f)
                : x(_x), y(_y), z(_z)
        {
        }
};


#endif
