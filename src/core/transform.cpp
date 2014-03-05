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
 *  File Name: transform.cpp
 *
 *  Purpose: Implementation of the transformation classes.
 *
 *  Creation Date: 18-02-2014
 *
 *  Last Modified:
 */

#include "transform.h"

// Matrix4x4 Utility Methods
Matrix4x4 Transpose (const Matrix4x4 &m) {
    return Matrix4x4 (m.m[0][0], m.m[1][0], m.m[2][0], m.m[3][0],
                      m.m[0][1], m.m[1][1], m.m[2][1], m.m[3][1],
                      m.m[0][2], m.m[1][2], m.m[2][2], m.m[3][2],
                      m.m[0][3], m.m[1][3], m.m[2][3], m.m[3][3]);
}
