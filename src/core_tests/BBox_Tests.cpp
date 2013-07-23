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
 *  File Name:
 *
 *  Purpose:
 *
 *  Creation Date: 19-07-2013
 *
 *  Last Modified: Mon 22 Jul 2013 05:49:37 PM PDT
 */

#include "BBox_Tests.h"

// Tests that the constructor defaults 0s correctly
TEST_F(BBoxTest, ConstructorWithoutArgsWorks) {
    BBox b;

    // Since we know the Point constructor works, just test one value of each
    // point so that we know the values propogated through correctly.
    EXPECT_EQ (INFINITY, b.pMin.x);
    EXPECT_EQ (-INFINITY, b.pMax.x);
}
