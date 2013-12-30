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
 *  Last Modified: Thu 01 Aug 2013 05:33:53 PM PDT
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

   
    // Which one of the following expectations is true:
    //  1.) One point, as a whole, will be considered the min or max point.
    //  2.) The bounding box should surround the *whole* area defined by the
    //      points. This means that whichever component of either point is
    //      the greatest is the maximum.
    //  
    //EXPECT_EQ (p2.y, b.pMin.y);
    //EXPECT_EQ (p1.y, b.pMax.y);
    EXPECT_EQ (p1.y, b.pMin.y);
    EXPECT_EQ (p2.y, b.pMax.y);
}


// Test the happy path case.
TEST_F(BBoxTest, UnionWithBoxAndPointWorks) {
    BBox b(Point (1, 1, 1), Point (2, 2, 2));
    Point p (3, 3, 3);

    BBox r = Union(b, p);

    EXPECT_EQ (1, r.pMin.y);
    EXPECT_EQ (3, r.pMax.y);
}


TEST_F(BBoxTest, UnionWithTwoBoxesWorks) {
    BBox b1(Point (1, 1, 1), Point (2, 2, 2));
    BBox b2(Point (2, 2, 2), Point (3, 3, 3));

    BBox r = Union (b1, b2);

    EXPECT_EQ (1, r.pMin.y);
    EXPECT_EQ (3, r.pMax.y);
}


TEST_F(BBoxTest, OverlapsDetectsOverlap) {
    BBox b1(Point (1, 1, 1), Point (2, 2, 2));
    BBox b2(Point (2, 2, 2), Point (3, 3, 3));

    bool result = b1.Overlaps(b2);

    EXPECT_TRUE (result);
}


TEST_F(BBoxTest, OverlapsDetectsNonOverlap) {
    BBox b1(Point (1, 1, 1), Point (2, 2, 2));
    BBox b2(Point (3, 3, 3), Point (4, 4, 4));

    bool result = b1.Overlaps(b2);

    EXPECT_FALSE (result);
}


TEST_F(BBoxTest, OverlapsDetectsNonOverlapOnlyOneVertexOff) {
    BBox b1(Point (1, 1, 1), Point (2, 2, 2));
    BBox b2(Point (3, 2, 2), Point (4, 4, 4));

    bool result = b1.Overlaps(b2);

    EXPECT_FALSE (result);
}


TEST_F(BBoxTest, InsideDetectsPointInside) {
    BBox b (Point (1, 1, 1), Point (3, 3, 3));
    Point p (2, 2, 2);

    bool result = b.Inside (p);

    EXPECT_TRUE (result);
}


TEST_F(BBoxTest, InsideDetectsPointOutside) {
    BBox b (Point (1, 1, 1), Point (3, 3, 3));
    Point p (4, 4, 4);

    bool result = b.Inside (p);

    EXPECT_FALSE (result);
}


TEST_F(BBoxTest, InsideDetectsPointOnBorderAsInside) {
    BBox b (Point (1, 1, 1), Point (3, 3, 3));
    Point p (3, 3, 3);

    bool result = b.Inside (p);

    EXPECT_TRUE (result);
}


TEST_F(BBoxTest, ExpandByPositiveValueWorks) {
    BBox b (Point (2, 2, 2), Point (3, 3, 3));
    float delta = 1.0;

    b.Expand (delta);

    EXPECT_EQ (1, b.pMin.x);
    EXPECT_EQ (1, b.pMin.y);
    EXPECT_EQ (1, b.pMin.z);

    EXPECT_EQ (4, b.pMax.x);
    EXPECT_EQ (4, b.pMax.y);
    EXPECT_EQ (4, b.pMax.z);
}


TEST_F(BBoxTest, ExpandByNegativeValueWorks) {
    BBox b (Point (1, 1, 1), Point (4, 4, 4));
    float delta = -1.0;

    b.Expand (delta);

    EXPECT_EQ (2, b.pMin.x);
    EXPECT_EQ (2, b.pMin.y);
    EXPECT_EQ (2, b.pMin.z);

    EXPECT_EQ (3, b.pMax.x);
    EXPECT_EQ (3, b.pMax.y);
    EXPECT_EQ (3, b.pMax.z);
}


TEST_F(BBoxTest, SurfaceAreaWorks) {
	BBox b (Point (0, 0, 0), Point (2, 2, 2));

	float area = b.SurfaceArea();

	EXPECT_FLOAT_EQ (24.f, area);
}


TEST_F(BBoxTest, SurfaceAreaDegenerateBBoxWorks) {
	BBox b (Point(0, 0, 0), Point (0, 0, 0));

	float area = b.SurfaceArea();

	EXPECT_FLOAT_EQ (0.f, area);
}


TEST_F(BBoxTest, VolumeWorks) {
	BBox b (Point (0, 0, 0), Point (2, 2, 2));

	float area = b.Volume();

	EXPECT_FLOAT_EQ (8.f, area);
}


TEST_F(BBoxTest, VolumeDegenerateBBoxWorks) {
	BBox b (Point (0, 0, 0), Point (0, 0, 0));

	float area = b.Volume();

	EXPECT_FLOAT_EQ (0.f, area);
}


TEST_F(BBoxTest, MaximumExtentWorks) {
	BBox b (Point (0, 0, 0), Point (1, 2, 3));

	int longest_axis = b.MaximumExtent();

	EXPECT_EQ (2, longest_axis);
}


TEST_F(BBoxTest, MaximumExtentDegenerateBBoxWorks) {
	BBox b (Point (0, 0, 0), Point (0, 0, 0));

	int longest_axis = b.MaximumExtent();

	EXPECT_EQ (2, longest_axis);
}


TEST_F(BBoxTest, MaximumExtentNegativeAxisWorks) {
	BBox b (Point (0, 0, 0), Point (-3, 0, 1));

	int longest_axis = b.MaximumExtent();

	EXPECT_EQ (0, longest_axis);
}

// Lerp Tests
TEST_F(BBoxTest, LerpZeroOneWorks) {
    BBox b (Point (0, 0, 0), Point (1, 1, 1));

    Point p = b.Lerp (1, 1, 1);

    EXPECT_EQ (1, p.x);
    EXPECT_EQ (1, p.y);
    EXPECT_EQ (1, p.z);
}

TEST_F(BBoxTest, LerpMidwayWorks) {
    BBox b (Point (0, 0, 0), Point (1, 1, 1));

    Point p = b.Lerp (.5, .5, .5);

    EXPECT_EQ (.5, p.x);
    EXPECT_EQ (.5, p.y);
    EXPECT_EQ (.5, p.z);
}

TEST_F(BBoxTest, LerpDegenerateWorks) {
    BBox b (Point (0, 0, 0), Point (0, 0, 0));

    Point p = b.Lerp (1, 1, 1);

    EXPECT_EQ (0, p.x);
    EXPECT_EQ (0, p.y);
    EXPECT_EQ (0, p.z);
}

// Offset Tests
TEST_F(BBoxTest, OffsetMidwayWorks) {
    BBox b (Point (0, 0, 0), Point (2, 2, 2));

    Vector v = b.Offset (Point (1, 1, 1));

    EXPECT_EQ (.5, v.x);
    EXPECT_EQ (.5, v.y);
    EXPECT_EQ (.5, v.z);
}

// This test crashes because Offset has no
// divide by zero checking.
TEST_F(BBoxTest, OffsetDegenerateWorks) {
    BBox b (Point (0, 0, 0), Point (0, 0, 0));

    Vector v = b.Offset (Point (1, 1, 1));

    EXPECT_EQ (.5, v.x);
    EXPECT_EQ (.5, v.y);
    EXPECT_EQ (.5, v.z);
}

// Bounding Sphere Tests
