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
 *  File Name: transform.h
 *
 *  Purpose: Define classes and structures to perform translations.
 *
 *  Creation Date: 16-01-2014
 */


////////////////////
// struct: Matrix4x4
//
// Purpose:
//      Provide a transformation matrix and corresponding functinoality.
//
// Notes:
//      This is setup as a struct in the book.
//          - To my understanding the only significant difference between a
//            struct and a class is the default access level.
//              - A struct's members are public by default whereas a classes
//                are private.
//          - It is also my understanding that in the context of C++ where
//            classes are used to make objects that can be acted upon with
//            their member functions, structs should be reserved for POD types
//            (plain old data) that simply needs organization and no other
//            functionality.
////////////////////

#include <array>

class Matrix4x4 {
    public:
        std::array <std::array <float, 4>, 4> m;

        // Constructors
        Matrix4x4 () {
            m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.f;

            m[0][1] = m[0][2] = m[0][3] = 0.f;
            m[1][0] = m[1][2] = m[1][3] = 0.f;
            m[2][0] = m[2][1] = m[2][3] = 0.f;
            m[3][0] = m[3][1] = m[3][2] = 0.f;
        }

        Matrix4x4 (float mat[4][4]) :
                m( {{ {{mat[0][0], mat[0][1], mat[0][2], mat[0][3]}},
                     {{mat[1][0], mat[1][1], mat[1][2], mat[1][3]}},
                     {{mat[2][0], mat[2][1], mat[2][2], mat[2][3]}},
                     {{mat[3][0], mat[3][1], mat[3][2], mat[3][3]}} }} )
        {}

        Matrix4x4 (float m00, float m01, float m02, float m03,
                   float m10, float m11, float m12, float m13,
                   float m20, float m21, float m22, float m23,
                   float m30, float m31, float m32, float m33) :
                m( {{ {{m00, m01, m02, m03}}, {{m10, m11, m12, m13}},
                    {{m20, m21, m22, m23}}, {{m30, m31, m32, m33}} }} )
        {} 


    // Operators
    bool operator== (Matrix4x4 mx) {
        std::array <std::array <float, 4>, 4>::const_iterator it1, it2;

        it1 = this->m.cbegin();
        it2 = mx.m.cbegin();

        for (; it1 < m.end(); ++it1, ++it2) {
            if (*it1 != *it2)
                return false;
        }

        return true;
    }

    bool operator!= (Matrix4x4 mx) {
        std::array <std::array <float, 4>, 4>::const_iterator it1, it2;

        it1 = this->m.cbegin();
        it2 = mx.m.cbegin();

        for (; it1 < m.end(); ++it1, ++it2) {
            if (*it1 != *it2)
                return true;
        }

        return false;
    }

    // Utility Methods
    static Matrix4x4 Mul (Matrix4x4 m1, Matrix4x4 m2)
    {
        Matrix4x4 r;

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                r.m[i][j] = (m1.m[i][0] * m2.m[0][j]) +
                            (m1.m[i][1] * m2.m[1][j]) +
                            (m1.m[i][2] * m2.m[2][j]) +
                            (m1.m[i][3] * m2.m[3][j]);
            }
        }

        return r;
    }

    friend Matrix4x4 Transpose (const Matrix4x4&);
    friend Matrix4x4 Inverse (const Matrix4x4&);
};
