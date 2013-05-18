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
 *  File Name: Ray_Tests.cpp
 *
 *  Purpose:
 *
 *  Creation Date: 29-04-2013
 *
 *  Last Modified: Fri 17 May 2013 01:08:40 PM PDT
 */

#include "Ray_Tests.h"


// Tests that the constructor defaults 0s correctly
TEST_F(RayTest, ConstructorWithoutArgsWorks) {
    Ray a;

    // Origin
	EXPECT_EQ (0, a.o.x);
	EXPECT_EQ (0, a.o.y);
	EXPECT_EQ (0, a.o.z);

    // Direction
	EXPECT_EQ (0, a.d.x);
	EXPECT_EQ (0, a.d.y);
	EXPECT_EQ (0, a.d.z);

    // Parametric Range: minimum t and maximum t
    EXPECT_EQ (1e-3f, a.mint);
    EXPECT_EQ (INFINITY, a.maxt);
}
