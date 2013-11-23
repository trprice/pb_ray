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
 *  File Name: pb_ray.h
 *
 *  Purpose: Provides high level settings, definitions, etc.
 *
 *  Creation Date: 22-07-2013
 *
 *  Last Modified: Mon 22 Jul 2013 05:01:08 PM PDT
 */

#if defined(_WIN32) || defined(WIN62)
#define PB_RAY_WINDOWS
#endif

#ifndef INFINITY
#define INFINITY FLT_MAX
#endif

#include <math.h>
#include <assert.h>
#include <algorithm>
using std::min;
using std::max;


// Global Inline Functions
inline float Lerp (float t, float v1, float v2) {
	return (1.f - t) * v1 + t * v2;
}