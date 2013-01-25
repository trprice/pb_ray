/*
 *  Vector_Tests.cpp
 *  p_ray
 *
 *  Created by Taylor Price on 8/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Vector_Tests.h"

// Tests that the constructor defaults 0s correctly
TEST_F(VectorTest, ConstructorWithoutArgsWorks) {
    Vector a;

	EXPECT_EQ (0, a.x);
	EXPECT_EQ (0, a.y);
	EXPECT_EQ (0, a.z);
}


// Tests that the + operator works appropriately.
TEST_F(VectorTest, OperatorPlusWorks) {
	Vector a (1, 1, 1);
	Vector b (2, 2, 2);
	
	Vector c = a + b;
	
	EXPECT_EQ (3, c.x);
	EXPECT_EQ (3, c.y);
	EXPECT_EQ (3, c.z);
}


// Tests that the += operator works appropriately.
TEST_F(VectorTest, OperatorPlusEqualsWorks) {
    Vector a (1, 1, 1);
    Vector b (2, 2, 2);

    b += a;

	EXPECT_EQ (3, b.x);
	EXPECT_EQ (3, b.y);
	EXPECT_EQ (3, b.z);
}


// Tests that the - operator works appropriately.
TEST_F(VectorTest, OperatorMinusWorks) {
	Vector a (2, 2, 2);
	Vector b (1, 1, 1);
	
	Vector c = a - b;
	
	EXPECT_EQ (1, c.x);
	EXPECT_EQ (1, c.y);
	EXPECT_EQ (1, c.z);
}


// Tests that the -= operator works appropriately.
TEST_F(VectorTest, OperatorMinusEqualsWorks) {
    Vector a (1, 1, 1);
    Vector b (2, 2, 2);

    b -= a;

	EXPECT_EQ (1, b.x);
	EXPECT_EQ (1, b.y);
	EXPECT_EQ (1, b.z);
}


// Tests that the * operator works appropriately.
TEST_F(VectorTest, OperatorStarWorks) {
	Vector a (1, 1, 1);

    Vector b = a * 2;
	
	EXPECT_EQ (2, b.x);
	EXPECT_EQ (2, b.y);
	EXPECT_EQ (2, b.z);
}


// Tests that the *= operator works appropriately.
TEST_F(VectorTest, OperatorStarEqualsWorks) {
    Vector a (1, 1, 1);

    a *= 3;

	EXPECT_EQ (3, a.x);
	EXPECT_EQ (3, a.y);
	EXPECT_EQ (3, a.z);
}


// Test the / (divide) operator.
TEST_F(VectorTest, OperatorDivideWorks) {
    Vector a (2, 2, 2);
    
    Vector b = a / 2;

    EXPECT_EQ (1, b.x);
    EXPECT_EQ (1, b.y);
    EXPECT_EQ (1, b.z);
}


// Test the unary negation operator.
TEST_F (VectorTest, OperatorUnaryNegationWorks) {
    const Vector a (3, 3, 3);

    Vector b = -a;

    EXPECT_EQ (-3, b.x);
    EXPECT_EQ (-3, b.y);
    EXPECT_EQ (-3, b.z);
}


// Test the [] const operator.
TEST_F (VectorTest, OperatorConstBracketsWork) {
    const Vector a (1, 2, 3);

    EXPECT_EQ (1, a[0]);
    EXPECT_EQ (2, a[1]);
    EXPECT_EQ (3, a[2]);
}


// Test that the [] non-const operator returns a reference.
//      Make sure we get the value and that it can be changed.
TEST_F (VectorTest, OperatorBracketsNonConstReturnsRef) {
    Vector a (1, 2, 3);

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


