/*
 *  Point_Tests.cpp
 *  p_ray
 *
 *  Created by Taylor Price on 8/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
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
TEST_F(PointTest, OperatorPlusWorksWithPositiveValues) {
    Point p1; // 0, 0, 0
    Vector v (1, 1, 1);

    Point p2 = p1 + v;

    EXPECT_EQ (1, p2.x);
    EXPECT_EQ (1, p2.y);
    EXPECT_EQ (1, p2.z);
}

TEST_F(PointTest, OperatorPlusWorksWithNegativeValues) {
    Point p1; // 0, 0, 0
    Vector v (-1, -1, -1);

    Point p2 = p1 + v;

    EXPECT_EQ (-1, p2.x);
    EXPECT_EQ (-1, p2.y);
    EXPECT_EQ (-1, p2.z);
}

TEST_F(PointTest, OperatorPlusEqualsWorksWithPositiveValues) {
    Point p1; // 0, 0, 0
    Vector v (1, 1, 1);

    p1 += v;

    EXPECT_EQ (1, p1.x);
    EXPECT_EQ (1, p1.y);
    EXPECT_EQ (1, p1.z);
}

TEST_F(PointTest, OperatorPlusEqualsWorksWithNegativeValues) {
    Point p1; // 0, 0, 0
    Vector v (-1, -1, -1);

    p1 += v;

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

TEST_F(PointTest, DistanceWorks) {
    Point p1 (2, 2, 1), p2 (0, 0, 0);

    EXPECT_EQ (3, Distance (p1, p2));
}

TEST_F(PointTest, DistanceSquaredWorks) {
    Point p1 (2, 2, 1), p2 (0, 0, 0);

    EXPECT_EQ (9, DistanceSquared (p1, p2));
}

TEST_F (PointTest, OperatorEqaulEqualTrue) {
    Point a (1, 1, 1), b (1, 1, 1);

    ASSERT_TRUE (a == b);
}

TEST_F (PointTest, OperatorEqaulEqualFalse) {
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
