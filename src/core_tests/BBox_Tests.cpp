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
 *  Last Modified: Tue 23 Jul 2013 05:43:30 PM PDT
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


// Make sure the single point being enclosed is properly propogated to
// the points.
TEST_F(BBoxTest, ConstructorToEncloseASinglePointWorks) {
    Point p (1, 1, 1);
    BBox b (p);

    // Since we know the Point constructor works, just test one value of each
    // point so that we know the values propogated through correctly.
    EXPECT_EQ (p.x, b.pMin.x);
    EXPECT_EQ (p.x, b.pMax.x);
}


// Test the two point constructor happy path.
TEST_F(BBoxTest, ConstructorTwoPointsHappyPathWorks) {
    Point p1 (1, 1, 1);
    Point p2 (2, 2, 2);

    // Give them in increasing order so the calls to min and max don't matter.
    BBox b (p1, p2);

   
    // Make sure the correct point got into pMin and pMax.
    //  - Because we know the Point constructors work, only test a unique point.
    EXPECT_EQ (p1.x, b.pMin.x);
    EXPECT_EQ (p2.x, b.pMax.x);
}


// Make sure that the min and max calls work for appropriate points.
TEST_F(BBoxTest, ConstructorTwoSwappedPointsWorks) {
    Point p1 (1, 1, 1);
    Point p2 (2, 2, 2);

    // Swap the points to make sure the happy path works for swapped points.
    BBox b (p2, p1);

   
    // Make sure the correct point got into pMin and pMax.
    //  - Because we know the Point constructors work, only test a unique point.
    EXPECT_EQ (p1.x, b.pMin.x);
    EXPECT_EQ (p2.x, b.pMax.x);
}


// Try to fool the min and max calls by giving points that are not diagonally
// opposite each other.
//  - This may not happen in "real" situations, but we want to show that it's
//    a case that is invalid.
TEST_F(BBoxTest, ConstructorTwoSwappedNonDiagonalPointsWorks) {
    Point p1 (2, 1, 2);
    Point p2 (1, 2, 1);

    // Swap the points to make sure the happy path works for swapped points.
    BBox b (p2, p1);

   
    // Point 2 in this case should likely be considered the min point.
    EXPECT_EQ (p2.y, b.pMin.y);
    EXPECT_EQ (p1.y, b.pMax.y);
}
