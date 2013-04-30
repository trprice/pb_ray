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
 *  File Name: Point_Tests.cpp
 *
 *  Purpose: Unit tests for the Point class.
 *
 *  Creation Date:
 *
 *  Last Modified: Mon 29 Apr 2013 05:07:59 PM PDT
 */

#include "Point_Tests.h"

// Tests that the constructor defaults 0s correctly
TEST_F(PointTest, ConstructorWithoutArgsWorks) {
    Point a;

	EXPECT_EQ (0, a.x);
	EXPECT_EQ (0, a.y);
	EXPECT_EQ (0, a.z);
}

TEST_F(PointTest, ConstructorWithArgsWorks) {
    Point a(1,1,1);

	EXPECT_EQ (1, a.x);
	EXPECT_EQ (1, a.y);
	EXPECT_EQ (1, a.z);
}


// Test that adding a vector with the '+' operator offsets the Point correctly.
TEST_F(PointTest, OperatorPlusReturningVectorWorksWithPositiveValues) {
    Point p1; // 0, 0, 0
    Vector v (1, 1, 1);

    Point p2 = p1 + v;

    EXPECT_EQ (1, p2.x);
    EXPECT_EQ (1, p2.y);
    EXPECT_EQ (1, p2.z);
}

TEST_F(PointTest, OperatorPlusReturningVectorWorksWithNegativeValues) {
    Point p1; // 0, 0, 0
    Vector v (-1, -1, -1);

    Point p2 = p1 + v;

    EXPECT_EQ (-1, p2.x);
    EXPECT_EQ (-1, p2.y);
    EXPECT_EQ (-1, p2.z);
}

TEST_F(PointTest, OperatorPlusEqualsReturningVectorWorksWithPositiveValues) {
    Point p1; // 0, 0, 0
    Vector v (1, 1, 1);

    p1 += v;

    EXPECT_EQ (1, p1.x);
    EXPECT_EQ (1, p1.y);
    EXPECT_EQ (1, p1.z);
}

TEST_F(PointTest, OperatorPlusEqualsReturningVectorWorksWithNegativeValues) {
    Point p1; // 0, 0, 0
    Vector v (-1, -1, -1);

    p1 += v;

    EXPECT_EQ (-1, p1.x);
    EXPECT_EQ (-1, p1.y);
    EXPECT_EQ (-1, p1.z);
}

TEST_F(PointTest, OperatorPlusReturningPointWorksWithPositiveValues) {
    Point p1; // 0, 0, 0
    Point p2 (1, 1, 1);

    Point p3 = p1 + p2;

    EXPECT_EQ (1, p3.x);
    EXPECT_EQ (1, p3.y);
    EXPECT_EQ (1, p3.z);
}

TEST_F(PointTest, OperatorPlusReturningPointWorksWithNegativeValues) {
    Point p1; // 0, 0, 0
    Point p2 (-1, -1, -1);

    Point p3 = p1 + p2;

    EXPECT_EQ (-1, p3.x);
    EXPECT_EQ (-1, p3.y);
    EXPECT_EQ (-1, p3.z);
}

TEST_F(PointTest, OperatorPlusEqualsReturningPointWorksWithPositiveValues) {
    Point p1; // 0, 0, 0
    Point p2 (1, 1, 1);

    p1 += p2;

    EXPECT_EQ (1, p1.x);
    EXPECT_EQ (1, p1.y);
    EXPECT_EQ (1, p1.z);
}

TEST_F(PointTest, OperatorPlusEqualsReturningPointWorksWithNegativeValues) {
    Point p1; // 0, 0, 0
    Point p2 (-1, -1, -1);

    p1 += p2;

    EXPECT_EQ (-1, p1.x);
    EXPECT_EQ (-1, p1.y);
    EXPECT_EQ (-1, p1.z);
}

TEST_F(PointTest, OperatorMinusWorksWithPositiveValues) {
    Point p1; // 0, 0, 0
    Vector v (1, 1, 1);

    Point p2 = p1 - v;

    EXPECT_EQ (-1, p2.x);
    EXPECT_EQ (-1, p2.y);
    EXPECT_EQ (-1, p2.z);
}

TEST_F(PointTest, OperatorMinusWorksWithNegativeValues) {
    Point p1; // 0, 0, 0
    Vector v (-1, -1, -1);

    Point p2 = p1 - v;

    EXPECT_EQ (1, p2.x);
    EXPECT_EQ (1, p2.y);
    EXPECT_EQ (1, p2.z);
}

TEST_F(PointTest, OperatorMinusEqualsWorksWithPositiveValues) {
    Point p1; // 0, 0, 0
    Vector v (1, 1, 1);

    p1 -= v;

    EXPECT_EQ (-1, p1.x);
    EXPECT_EQ (-1, p1.y);
    EXPECT_EQ (-1, p1.z);
}

TEST_F(PointTest, OperatorMinusEqualsWorksWithNegativeValues) {
    Point p1; // 0, 0, 0
    Vector v (-1, -1, -1);

    p1 -= v;

    EXPECT_EQ (1, p1.x);
    EXPECT_EQ (1, p1.y);
    EXPECT_EQ (1, p1.z);
}

TEST_F(PointTest, OperatorMinusPointMinusPointForVector) {
    Point p1(1, 1, 1), p2 (0, 0, 0);

    Vector v = p1 - p2;

    EXPECT_EQ (1, v.x);
    EXPECT_EQ (1, v.y);
    EXPECT_EQ (1, v.z);
}

// Tests that the * operator works appropriately.
TEST_F(PointTest, OperatorStarWorksWithPositiveNumbers) {
	Point a (1, 1, 1);

    Point b = a * 2;
	
	EXPECT_EQ (2, b.x);
	EXPECT_EQ (2, b.y);
	EXPECT_EQ (2, b.z);
}

TEST_F(PointTest, OperatorStarWorksWithNegativeNumbers) {
	Point a (1, 1, 1);

    Point b = a * -2;
	
	EXPECT_EQ (-2, b.x);
	EXPECT_EQ (-2, b.y);
	EXPECT_EQ (-2, b.z);
}

// Tests that the *= operator works appropriately.
TEST_F(PointTest, OperatorStarEqualsWorksWithPositiveNumbers) {
    Point a (1, 1, 1);

    a *= 3;

	EXPECT_EQ (3, a.x);
	EXPECT_EQ (3, a.y);
	EXPECT_EQ (3, a.z);
}

TEST_F(PointTest, OperatorStarEqualsWorksWithNegativeNumbers) {
    Point a (1, 1, 1);

    a *= -3;

	EXPECT_EQ (-3, a.x);
	EXPECT_EQ (-3, a.y);
	EXPECT_EQ (-3, a.z);
}

TEST_F(PointTest, OperatorScalarDivideWorksWithPositiveNumbers) {
	Point a (2, 2, 2);

    Point b = a / 2;
	
	EXPECT_EQ (1, b.x);
	EXPECT_EQ (1, b.y);
	EXPECT_EQ (1, b.z);
}

TEST_F(PointTest, OperatorScalarDivideWorksWithNegativeNumbers) {
	Point a (2, 2, 2);

    Point b = a / -2;
	
	EXPECT_EQ (-1, b.x);
	EXPECT_EQ (-1, b.y);
	EXPECT_EQ (-1, b.z);
}

// Tests that the *= operator works appropriately.
TEST_F(PointTest, OperatorScalarDivideEqualsWorksWithPositiveNumbers) {
    Point a (3, 3, 3);

    a /= 3;

	EXPECT_EQ (1, a.x);
	EXPECT_EQ (1, a.y);
	EXPECT_EQ (1, a.z);
}

TEST_F(PointTest, OperatorScalarDivideEqualsWorksWithNegativeNumbers) {
    Point a (3, 3, 3);

    a /= -3;

	EXPECT_EQ (-1, a.x);
	EXPECT_EQ (-1, a.y);
	EXPECT_EQ (-1, a.z);
}

// Test the unary negation operator.
TEST_F (PointTest, OperatorUnaryNegationWorks) {
    const Point a (3, 3, 3);

    Point b = -a;

    EXPECT_EQ (-3, b.x);
    EXPECT_EQ (-3, b.y);
    EXPECT_EQ (-3, b.z);
}


// Test the [] const operator.
TEST_F (PointTest, OperatorBracketsConstWork) {
    const Point a (1, 2, 3);

    float x = a[0];
    float y = a[1];
    float z = a[2];

    EXPECT_EQ (1, x);
    EXPECT_EQ (2, y);
    EXPECT_EQ (3, z);
}


// Test that the [] non-const operator returns a reference.
//      Make sure we get the value and that it can be changed.
TEST_F (PointTest, OperatorBracketsNonConstReturnsRef) {
    Point a (1, 2, 3);

    // Test that the references get the correct values.
    float &x = a[0];
    float &y = a[1];
    float &z = a[2];

    EXPECT_EQ (1, x);
    EXPECT_EQ (2, y);
    EXPECT_EQ (3, z);

    // Because we got back references, test that we can
    // change the values in the actual vector.
    x = 4;
    y = 5;
    z = 6;

    EXPECT_EQ (4, a[0]);
    EXPECT_EQ (5, a[1]);
    EXPECT_EQ (6, a[2]);
}

TEST_F(PointTest, DistanceWorks) {
    Point p1 (2, 2, 1), p2 (0, 0, 0);

    EXPECT_EQ (3, Distance (p1, p2));
}

TEST_F(PointTest, DistanceSquaredWorks) {
    Point p1 (2, 2, 1), p2 (0, 0, 0);

    EXPECT_EQ (9, DistanceSquared (p1, p2));
}

TEST_F (PointTest, OperatorEqualEqualTrue) {
    Point a (1, 1, 1), b (1, 1, 1);

    ASSERT_TRUE (a == b);
}

TEST_F (PointTest, OperatorEqualEqualFalse) {
    Point a (1, 1, 1), b (2, 2, 2);

    ASSERT_FALSE (a == b);
}

TEST_F (PointTest, OperatorMinusEqualTrue) {
    Point a (1, 1, 1), b (2, 2, 2);

    ASSERT_TRUE (a != b);
}

TEST_F (PointTest, OperatorMinusEqualFalse) {
    Point a (1, 1, 1), b (1, 1, 1);

    ASSERT_FALSE (a != b);
}
