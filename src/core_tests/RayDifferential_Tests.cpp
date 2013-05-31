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
 *  File Name: RayDifferential_Tests.cpp
 *
 *  Purpose: Test the RayDifferential class
 *
 *  Creation Date: 30-05-2013
 *
 *  Last Modified: Thu May 30 22:41:13 2013
 */

#include "RayDifferential_Tests.h"

TEST_F(RayDifferentialTest, ConstructorWithoutArgsWorks) {
    RayDifferential rd;

    EXPECT_EQ (false, rd.hasDifferentials);

    // What about the rays?
    //      We've tested that the constructors of Ray, Point, and Vector work.
    //      Why would we need to test the values of everything in these classes again?
}
