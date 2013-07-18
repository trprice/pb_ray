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
 *  Last Modified: Wed 17 Jul 2013 05:46:12 PM PDT
 */

#include "RayDifferential_Tests.h"

TEST_F(RayDifferentialTest, ConstructorWithoutArgsWorks) {
    RayDifferential rd;

    EXPECT_EQ (false, rd.hasDifferentials);

    // What about the rays?
    //      We've tested that the constructors of Ray, Point, and Vector work,
    //      so don't bother testing those. We can get away with just testing
    //      that one of the values of one member of one ray is init'd. If it
    //      is, the rest will have worked correctly as proven by the other
    //      unit tests.
    
    // Check that the main ray was initialized.
	EXPECT_EQ (0, rd.o.x);
    
   
    // Check that one of the additional rays was initialized. 
	EXPECT_EQ (0, rd.rx.o.x);
}

TEST_F(RayDifferentialTest, ConstructorWithRayConstructorParametersWorks) {
    Point origin (1, 1, 1);
    Vector direction (2, 2, 2);

    RayDifferential rd (origin, direction);


    EXPECT_EQ (false, rd.hasDifferentials);

    // Check that the origin was propogated through the Ray constructor.
    EXPECT_EQ (1, rd.o.x);

    // Check that the direction was propogated through the Ray constructor.
    EXPECT_EQ (2, rd.d.x);
}

TEST_F(RayDifferentialTest, ConstructorWithRayWorks) {
    Point origin (1, 1, 1);
    Vector direction (2, 2, 2);
    Ray ray (origin, direction);

    RayDifferential rd (ray);

    EXPECT_EQ (false, rd.hasDifferentials);
}
