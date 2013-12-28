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
 *  File Name: pb_ray_h_tests.cpp
 *
 *  Purpose: Test code for inline functions in pb_ray.h
 *
 *  Creation Date: 27-12-2013
 *
 *  Last Modified:
 */

#include "pb_ray_h_tests.h"

TEST_F (PBRayHTest, LerpPointFiveZeroOne) {
    float m = Lerp (.5, 0, 1);

    EXPECT_EQ (.5, m);
}

TEST_F (PBRayHTest, LerpPointFiveNegativeOneOne) {
    float m = Lerp (.5, -1, 1);

    EXPECT_EQ (0, m);
}

TEST_F (PBRayHTest, LerpOneOneOne) {
    float m = Lerp (1, 1, 1);

    EXPECT_EQ (1, m);
}

