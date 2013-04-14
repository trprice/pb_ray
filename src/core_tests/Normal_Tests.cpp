/*
 *  Normal_Tests.cpp
 *  p_ray
 *
 *  Created by Taylor Price on 8/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Normal_Tests.h"

// Tests that the constructor defaults 0s correctly
TEST_F(NormalTest, ConstructorWithoutArgsWorks) {
    Normal a;

	EXPECT_EQ (0, a.x);
	EXPECT_EQ (0, a.y);
	EXPECT_EQ (0, a.z);
}


// Tests that the + operator works appropriately.
TEST_F(NormalTest, OperatorPlusWorks) {
	Normal a (1, 1, 1);
	Normal b (2, 2, 2);
	
	Normal c = a + b;
	
	EXPECT_EQ (3, c.x);
	EXPECT_EQ (3, c.y);
	EXPECT_EQ (3, c.z);
}


// Tests that the += operator works appropriately.
TEST_F(NormalTest, OperatorPlusEqualsWorks) {
    Normal a (1, 1, 1);
    Normal b (2, 2, 2);

    b += a;

	EXPECT_EQ (3, b.x);
	EXPECT_EQ (3, b.y);
	EXPECT_EQ (3, b.z);
}


// Tests that the - operator works appropriately.
TEST_F(NormalTest, OperatorMinusWorks) {
	Normal a (2, 2, 2);
	Normal b (1, 1, 1);
	
	Normal c = a - b;
	
	EXPECT_EQ (1, c.x);
	EXPECT_EQ (1, c.y);
	EXPECT_EQ (1, c.z);
}


// Tests that the -= operator works appropriately.
TEST_F(NormalTest, OperatorMinusEqualsWorks) {
    Normal a (1, 1, 1);
    Normal b (2, 2, 2);

    b -= a;

	EXPECT_EQ (1, b.x);
	EXPECT_EQ (1, b.y);
	EXPECT_EQ (1, b.z);
}


// Tests that the * operator works appropriately.
TEST_F(NormalTest, OperatorStarWorks) {
	Normal a (1, 1, 1);

    Normal b = a * 2;
	
	EXPECT_EQ (2, b.x);
	EXPECT_EQ (2, b.y);
	EXPECT_EQ (2, b.z);
}


// Tests that the *= operator works appropriately.
TEST_F(NormalTest, OperatorStarEqualsWorks) {
    Normal a (1, 1, 1);

    a *= 3;

	EXPECT_EQ (3, a.x);
	EXPECT_EQ (3, a.y);
	EXPECT_EQ (3, a.z);
}


// Test the / (divide) operator.
TEST_F(NormalTest, OperatorDivideWorks) {
    Normal a (2, 2, 2);
    
    Normal b = a / 2;

    EXPECT_EQ (1, b.x);
    EXPECT_EQ (1, b.y);
    EXPECT_EQ (1, b.z);
}


// Test the unary negation operator.
TEST_F (NormalTest, OperatorUnaryNegationWorks) {
    const Normal a (3, 3, 3);

    Normal b = -a;

    EXPECT_EQ (-3, b.x);
    EXPECT_EQ (-3, b.y);
    EXPECT_EQ (-3, b.z);
}


// Test the [] const operator.
TEST_F (NormalTest, OperatorBracketsConstWork) {
    const Normal a (1, 2, 3);

    float x = a[0];
    float y = a[1];
    float z = a[2];

    EXPECT_EQ (1, x);
    EXPECT_EQ (2, y);
    EXPECT_EQ (3, z);
}


// Test that the [] non-const operator returns a reference.
//      Make sure we get the value and that it can be changed.
TEST_F (NormalTest, OperatorBracketsNonConstReturnsRef) {
    Normal a (1, 2, 3);

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


// Test the dot product of two normals.
TEST_F (NormalTest, DotProductWorks) {
    Normal a (1, 1, 1);
    Normal b (2, 2, 2);

    float f = Dot (a, b);

    EXPECT_EQ (6, f);
}


// Test the dot product of perpendicular normals.
TEST_F (NormalTest, DotProductPerpendicularNormals) {
    Normal a (1, 0, 0);
    Normal b (0, 1, 0);

    float f = Dot (a, b);

    EXPECT_EQ (0, f);
}


// Test the dot product of two normals.
TEST_F (NormalTest, DotProductWithNegativeNormalValuesWorks) {
    Normal a (-1, -1, -1);
    Normal b (2, 2, 2);

    float f = Dot (a, b);

    EXPECT_EQ (-6, f);
}


// Test the dot product of two normals.
TEST_F (NormalTest, AbsDotProductWithNegativeNormalValuesWorks) {
    Normal a (-1, -1, -1);
    Normal b (2, 2, 2);

    float f = AbsDot (a, b);

    EXPECT_EQ (6, f);
}


// Test the cross product of two normals.
TEST_F (NormalTest, CrossProductDegenerateNormal) {
    Normal a (1, 1, 1);
    Normal b (2, 2, 2);

    Normal c = Cross (a, b);

	EXPECT_EQ (0, c.x);
	EXPECT_EQ (0, c.y);
	EXPECT_EQ (0, c.z);
}


// Test the cross product of two normals.
TEST_F (NormalTest, CrossProductWorks) {
    Normal a (-1, 1, 1);
    Normal b (2, 2, 2);

    Normal c = Cross (a, b);

    // Check the computed values.
	EXPECT_EQ (0, c.x);
	EXPECT_EQ (4, c.y);
	EXPECT_EQ (-4, c.z);

    // Make sure that we aren't looing at either a or b.
    EXPECT_NE (&c, &a);
    EXPECT_NE (&c, &b);
}


TEST_F (NormalTest, LengthSquaredWorks) {
    Normal a (1, 1, 1);

    EXPECT_EQ (3, a.LengthSquared());
}


TEST_F (NormalTest, LengthWorks) {
    Normal a (2, 2, 1); // Generates a length squared of 9.

    EXPECT_EQ (3, a.Length());
}


TEST_F (NormalTest, NormalizeWorks) {
    Normal a (2, 2, 2);

    Normal b = Normalize (a);

    float c = 2 / a.Length();
    
    EXPECT_FLOAT_EQ (c, b.x);
    EXPECT_FLOAT_EQ (c, b.y);
    EXPECT_FLOAT_EQ (c, b.z);

    // Check that the b is not pointing to a.
    EXPECT_NE (&b, &a);
}


TEST_F (NormalTest, CoordinateSystemXgtY) {
    Normal a (2, 1, 1);
    Normal b;
    Normal c;

    CoordinateSystem (a, &b, &c);

    float b_x = -1 * (1 / (sqrtf(5))),
          b_y = 0.f,
          b_z = -2 * (1 / (sqrtf(5)));

    EXPECT_FLOAT_EQ (b_x, b.x);
    EXPECT_FLOAT_EQ (b_y, b.y);
    EXPECT_FLOAT_EQ (b_z, b.z);

    float c_x = (a.y * b_z) - (a.z * b_y),
          c_y = (a.z * b_x) - (a.x * b_z),
          c_z = (a.x * b_y) - (a.y * b_x);

    EXPECT_FLOAT_EQ (c_x, c.x);
    EXPECT_FLOAT_EQ (c_y, c.y);
    EXPECT_FLOAT_EQ (c_z, c.z);
}


TEST_F (NormalTest, CoordinateSystemXltY) {
    Normal a (1, 2, 1);
    Normal b;
    Normal c;

    CoordinateSystem (a, &b, &c);

    float b_x = 0.f,
          b_y = -1 * (1 / (sqrtf(5))),
          b_z = -2 * (1 / (sqrtf(5)));

    EXPECT_FLOAT_EQ (b_x, b.x);
    EXPECT_FLOAT_EQ (b_y, b.y);
    EXPECT_FLOAT_EQ (b_z, b.z);

    float c_x = (a.y * b_z) - (a.z * b_y),
          c_y = (a.z * b_x) - (a.x * b_z),
          c_z = (a.x * b_y) - (a.y * b_x);

    EXPECT_FLOAT_EQ (c_x, c.x);
    EXPECT_FLOAT_EQ (c_y, c.y);
    EXPECT_FLOAT_EQ (c_z, c.z);
}


TEST_F (NormalTest, CoordinateSystemXEqualsY) {
    Normal a (1, 1, 2);
    Normal b;
    Normal c;

    CoordinateSystem (a, &b, &c);

    float b_x = 0.f,
          b_y = -2 * (1 / (sqrtf(5))),
          b_z = -1 * (1 / (sqrtf(5)));

    EXPECT_FLOAT_EQ (b_x, b.x);
    EXPECT_FLOAT_EQ (b_y, b.y);
    EXPECT_FLOAT_EQ (b_z, b.z);

    float c_x = (a.y * b_z) - (a.z * b_y),
          c_y = (a.z * b_x) - (a.x * b_z),
          c_z = (a.x * b_y) - (a.y * b_x);

    EXPECT_FLOAT_EQ (c_x, c.x);
    EXPECT_FLOAT_EQ (c_y, c.y);
    EXPECT_FLOAT_EQ (c_z, c.z);
}

TEST_F (NormalTest, OperatorEqaulEqualTrue) {
    Normal a (1, 1, 1), b (1, 1, 1);

    ASSERT_TRUE (a == b);
}

TEST_F (NormalTest, OperatorEqaulEqualFalse) {
    Normal a (1, 1, 1), b (2, 2, 2);

    ASSERT_FALSE (a == b);
}

TEST_F (NormalTest, OperatorMinusEqualTrue) {
    Normal a (1, 1, 1), b (2, 2, 2);

    ASSERT_TRUE (a != b);
}

TEST_F (NormalTest, OperatorMinusEqualFalse) {
    Normal a (1, 1, 1), b (1, 1, 1);

    ASSERT_FALSE (a != b);
}