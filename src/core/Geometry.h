/*
 *	pb_ray source code
 *	
 *	This file is part of pb_ray.
 *	
 *	pb_ray is free software; you can redistribute it and/or modify
 *	it under the terms of The MIT License (opensource.org/licenses/MIT).
 *	
 *	pb_ray is based the book "Physically Based Rendering" written by Matt Pharr
 *	and Greg Humphreys. The book and its contents are *not* licensed under
 *	The MIT License.
 *	
 *	pb_ray is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *	
 *	You should have received a copy of The MIT License along with this program.
 *	If not, see <http://www.opensource.org/licenses/MIT>
 *
 *
 *  File Name: Geometry.h
 *
 *  Purpose:
 *
 *  Creation Date: 8/9/12
 *
 *  Last Modified: Wed 22 May 2013 05:27:05 PM PDT
 */

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "assert.h"
#include "math.h"

/***************
 ***************
 * Forward Declarations
 *
 *      Possibly pull these into a header?
 ***************
 ***************/
class Vector;
class Point;
class Normal;
class Ray;


/***************
 ***************
 * Global Constants
 ***************
 ***************/
#define RAY_EPSILON 1e-3f


/***************
 ***************
 * Geometry Classes
 ***************
 ***************/

////////////////////
// Class: Vector
//
// Purpose:
//      Encapsulate the data for a vector and make related functionality
//      available.
////////////////////
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

        explicit Vector (const Point &n); // Force an explicit conversion.
        explicit Vector (const Normal &n); // Force an explicit conversion.


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

        bool operator==(const Vector &v) const {
            return x == v.x && y == v.y && z == v.z;
        }

        bool operator!=(const Vector &v) const {
            return x != v.x || y != v.y || z != v.z;
        }

        
        // Member Functions
        float LengthSquared() const {
            return x*x + y*y + z*z;
        }

        float Length() const {
            return sqrtf (LengthSquared());
        }
};


////////////////////
// Class: Point
//
// Purpose:
//      Encapsulate the data for a point and make related functionality
//      available.
////////////////////
class Point {
    public:
        //////////
        // Data Members
        //      These are public for several reasons, even though it's not
        //      good practice.
        //          1.) Ease of access
        //          2.) No overhead of function calls for accessors.
        //////////
        float x, y, z;

        
        //////////
        // Constructors
        //////////
        Point (float _x = 0.f, float _y = 0.f, float _z = 0.f)
                : x(_x), y(_y), z(_z)
        {
        }


        //////////
        // Operators
        //////////

        // Offset a point by a Vector by adding ('+' and '+=')
        //      or subtracting ('-' or '-=').
        Point operator+ (const Vector &v) const {
            return Point (x + v.x, y + v.y, z + v.z);
        }

        Point &operator+= (const Vector &v) {
            x += v.x; y += v.y; z += v.z;
            return *this;
        }

        Point operator- (const Vector &v) const {
            return Point (x - v.x, y - v.y, z - v.z);
        }

        Point &operator-= (const Vector &v) {
            x -= v.x; y -= v.y; z -= v.z;
            return *this;
        }

        // Get the Vector between two points by subtracting ('-').
        Vector operator- (const Point &p) const {
            return Vector (x + p.x, y + p.y, z + p.z);
        }

        // Operators for adding and subracting Points from
        //  each other to get a new Point instead of a Vector.
        Point operator+ (const Point &p) const {
            return Point (x + p.x, y + p.y, z + p.y);
        }

        Point &operator+= (const Point &v) {
            x += v.x; y += v.y; z += v.z;
            return *this;
        }

        
        // Scalar Multiplication
        Point operator*(float f) const {
            return Point (f * x, f * y, f * z);
        }

        Point& operator*=(float f) {
            x *= f;
            y *= f;
            z *= f;

            return *this;
        }


        // Scalar Division
        Point operator/(float f) const {
            assert (f != 0);
            float inverse =  1.f / f;
            return Point (x * inverse, y * inverse, z * inverse);
        }

        Point& operator/=(float f) {
            assert (f != 0);

            float inverse =  1.f / f;
            
            x *= inverse;
            y *= inverse;
            z *= inverse;

            return *this;
        }


        // Negation operator
        Point operator-() const {
            return Point (-x, -y, -z);
        }


        // Access operators
        float operator[](int i) const {
            assert ((i >= 0) && (i <= 2));
            return (&x)[i];
        }

        float &operator[](int i) {
            assert ((i >= 0) && (i <= 2));
            return (&x)[i];
        }


        // Comparison Operators
        bool operator==(const Point &v) const {
            return x == v.x && y == v.y && z == v.z;
        }

        bool operator!=(const Point &v) const {
            return x != v.x || y != v.y || z != v.z;
        }

};


////////////////////
// Class: Normal
//
// Purpose:
//      Encapsulate the data for a normal and make related functionality
//      available.
////////////////////
class Normal {
    public:
        // Data Members
        //      These are public for several reasons, even though it's not
        //      good practice.
        //          1.) Ease of access
        //          2.) No overhead of function calls for accessors.
        float x, y, z;


        // Constructors
        Normal (float _x = 0.f, float _y = 0.f, float _z = 0.f)
                : x(_x), y(_y), z(_z)
        {
        }


        // Operators
        Normal operator+(const Normal &v) const {
            return Normal (x + v.x, y + v.y, z + v.z);
        }

        Normal& operator+=(const Normal &v) {
            x += v.x;
            y += v.y;
            z += v.z;

            return *this;
        }

        Normal operator-(const Normal &v) const {
            return Normal (x - v.x, y - v.y, z - v.z);
        }

        Normal& operator-=(const Normal &v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;

            return *this;
        }

        Normal operator*(float f) const {
            return Normal (f * x, f * y, f * z);
        }

        Normal& operator*=(float f) {
            x *= f;
            y *= f;
            z *= f;

            return *this;
        }

        Normal operator/(float f) const {
            assert (f != 0);
            float inverse =  1.f / f;
            return Normal (x * inverse, y * inverse, z * inverse);
        }

        Normal& operator/=(float f) {
            assert (f != 0);

            float inverse =  1.f / f;
            
            x *= inverse;
            y *= inverse;
            z *= inverse;

            return *this;
        }

        Normal operator-() const {
            return Normal (-x, -y, -z);
        }

        float operator[](int i) const {
            assert ((i >= 0) && (i <= 2));
            return (&x)[i];
        }

        float &operator[](int i) {
            assert ((i >= 0) && (i <= 2));
            return (&x)[i];
        }

        bool operator==(const Normal &v) const {
            return x == v.x && y == v.y && z == v.z;
        }

        bool operator!=(const Normal &v) const {
            return x != v.x || y != v.y || z != v.z;
        }

        
        // Member Functions
        float LengthSquared() const {
            return x*x + y*y + z*z;
        }

        float Length() const {
            return sqrtf (LengthSquared());
        }
};


////////////////////
// Class: Ray
//
// Purpose:
//      Encapsulate the data for a ray and make related functionality
//      available.
////////////////////
class Ray {
    public:
        ///////////////
        // Data Members
        //      These are public for several reasons, even though it's not
        //      good practice.
        //          1.) Ease of access
        //          2.) No overhead of function calls for accessors.
        ///////////////
        Point o; // The origin of the ray.
        Vector d; // The direction of the ray.

        // These are scalar constants used to limit the ray to a section
        //      along it's direction vector.
        //      The parametric form of the ray giving the points it passes
        //      through is as follows:
        //          r(t) = o + td where 0 <= t <= infinity
        //
        //      These allow us to specify the beginning and ending points
        //      of a section of the ray.
        mutable float mint, maxt;

        // A time stamp to allow for motion blur.
        float time;


        ///////////////
        // Constructors
        ///////////////

        // No args constructor. Origin & direction are (0,0,0).
        Ray() : mint(RAY_EPSILON), maxt(INFINITY), time(0.f) { }

        // Constructor with args
        Ray (const Point &origin, const Vector &direction,
             float start = RAY_EPSILON, float end = INFINITY, float t = 0.f)
            : o(origin), d(direction), mint(start), maxt(end), time(t) { }

        
        ///////////////
        // Operators
        ///////////////

        // Find the point at a particular position along the ray.
        Point operator()(float t) const { return o + d * t; }
};


/***************
 ***************
 * Vector Inline Functions
 ***************
 ***************/

// Compute the dot product of two vectors.
inline float Dot (const Vector &v1, const Vector &v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

// Compute the dot product of two normals.
inline float Dot (const Normal &n1, const Normal &n2) {
    return (n1.x * n2.x) + (n1.y * n2.y) + (n1.z * n2.z);
}

// Compute the dot product of a vector and a normal.
inline float Dot (const Vector &v, const Normal &n) {
    return (v.x * n.x) + (v.y * n.y) + (v.z * n.z);
}

// Compute the dot product of two vectors.
inline float AbsDot (const Vector &v1, const Vector &v2) {
    return fabsf (Dot (v1, v2));
}

// Compute the dot product of two normals.
inline float AbsDot (const Normal &n1, const Normal &n2) {
    return fabsf (Dot (n1, n2));
}

// Compute the dot product of a vector and a normal.
inline float AbsDot (const Vector &v, const Normal &n) {
    return fabsf (Dot (v, n));
}

// Constructors
inline Vector::Vector (const Point &p)
    : x(p.x), y(p.y), z(p.z) {
}

inline Vector::Vector (const Normal &n)
    : x(n.x), y(n.y), z(n.z) {
}


////////////////////
// Function:
//      Cross
//
// Purpose:
//      Compute the cross product of two vectors, normals,
//      and a vector and a normal.
//
// Parameters:
//      const Vector &v1, const Vector &v2
//      const Vector &v, const Normal &n
//      const const Normal &n, Vector &v 
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

inline Vector Cross (const Vector &v, const Normal n) {
    return Vector (((v.y * n.z) - (v.z * n.y)),
                   ((v.z * n.x) - (v.x * n.z)),
                   ((v.x * n.y) - (v.y * n.x))
                  );
}

inline Vector Cross (const Normal &n, const Vector v) {
    return Vector (((n.y * v.z) - (n.z * v.y)),
                   ((n.z * v.x) - (n.x * v.z)),
                   ((n.x * v.y) - (n.y * v.x))
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

inline Normal Normalize (const Normal &n) {
    return n / n.Length();
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


/***************
 ***************
 * Point Inline Functions
 ***************
 ***************/
inline float Distance (const Point &p1, const Point &p2) {
    return (p1 - p2).Length();
}

inline float DistanceSquared (const Point &p1, const Point &p2) {
    return (p1 - p2).LengthSquared();
}

#endif
