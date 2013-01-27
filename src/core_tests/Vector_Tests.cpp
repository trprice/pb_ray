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
TEST_F (VectorTest, OperatorBracketsConstWork) {
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


// Test the dot product of two vectors.
TEST_F (VectorTest, DotProductWorks) {
    Vector a (1, 1, 1);
    Vector b (2, 2, 2);

    float f = Dot (a, b);

    EXPECT_EQ (6, f);
}


// Test the dot product of perpendicular vectors.
TEST_F (VectorTest, DotProductPerpendicularVectors) {
    Vector a (1, 0, 0);
    Vector b (0, 1, 0);

    float f = Dot (a, b);

    EXPECT_EQ (0, f);
}


// Test the dot product of two vectors.
TEST_F (VectorTest, DotProductWithNegativeVectorValuesWorks) {
    Vector a (-1, -1, -1);
    Vector b (2, 2, 2);

    float f = Dot (a, b);

    EXPECT_EQ (-6, f);
}


// Test the dot product of two vectors.
TEST_F (VectorTest, AbsDotProductWithNegativeVectorValuesWorks) {
    Vector a (-1, -1, -1);
    Vector b (2, 2, 2);

    float f = AbsDot (a, b);

    EXPECT_EQ (6, f);
}


// Test the cross product of two vectors.
TEST_F (VectorTest, CrossProductDegenerateVector) {
    Vector a (1, 1, 1);
    Vector b (2, 2, 2);

    Vector c = Cross (a, b);

	EXPECT_EQ (0, c.x);
	EXPECT_EQ (0, c.y);
	EXPECT_EQ (0, c.z);
}


// Test the cross product of two vectors.
TEST_F (VectorTest, CrossProductWorks) {
    Vector a (-1, 1, 1);
    Vector b (2, 2, 2);

    Vector c = Cross (a, b);

	EXPECT_EQ (0, c.x);
	EXPECT_EQ (4, c.y);
	EXPECT_EQ (-4, c.z);
}


TEST_F (VectorTest, LengthSquaredWorks) {
    Vector a (1, 1, 1);

    EXPECT_EQ (3, a.LengthSquared());
}


TEST_F (VectorTest, LengthWorks) {
    Vector a (2, 2, 1); // Generates a length squared of 9.

    EXPECT_EQ (3, a.Length());
}


TEST_F (VectorTest, NormalizeWorks) {
    // This will generate a length of 1 and will make
    // the tests below work.
    Vector a (1, 0, 0);

    Vector b = Normalize (a);
    
    // For some reason, EXPECT_EQ doesn't like
    //      comparing float values.
    //      Check the googletest documentation so
    //      that we can do a better test than this.
    EXPECT_EQ (1, b.x);
    EXPECT_EQ (0, b.y);
    EXPECT_EQ (0, b.z);

    // Check that the b is not pointing to a.
    EXPECT_NE (&b, &a);
}