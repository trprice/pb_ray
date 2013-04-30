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
 *  File Name: Normal_Tests.cpp
 *
 *  Purpose: Unit tests for the Normal class in Geometry.h
 *
 *  Creation Date: 8/9/12
 *
 *  Last Modified: Mon 29 Apr 2013 05:07:44 PM PDT
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


TEST_F (NormalTest, CrossProductDegenerateNormalVectorFirst) {
    Vector v (1, 1, 1);
    Normal n (2, 2, 2);

    Vector c = Cross (v, n);

	EXPECT_EQ (0, c.x);
	EXPECT_EQ (0, c.y);
	EXPECT_EQ (0, c.z);
}


TEST_F (NormalTest, CrossProductWorksVectorFirst) {
    Vector v (-1, 1, 1);
    Normal n (2, 2, 2);

    Vector c = Cross (v, n);

    // Check the computed values.
	EXPECT_EQ (0, c.x);
	EXPECT_EQ (4, c.y);
	EXPECT_EQ (-4, c.z);

    // Make sure that we aren't looing at v.
    EXPECT_NE (&c, &v);
}


TEST_F (NormalTest, CrossProductDegenerateNormalNormalFirst) {
    Normal n (1, 1, 1);
    Vector v (2, 2, 2);

    Vector c = Cross (n, v);

	EXPECT_EQ (0, c.x);
	EXPECT_EQ (0, c.y);
	EXPECT_EQ (0, c.z);
}


TEST_F (NormalTest, CrossProductWorksNormalFirst) {
    Normal n (-1, 1, 1);
    Vector v (2, 2, 2);

    Vector c = Cross (n, v);

    // Check the computed values.
	EXPECT_EQ (0, c.x);
	EXPECT_EQ (4, c.y);
	EXPECT_EQ (-4, c.z);

    // Make sure that we aren't looing at v.
    EXPECT_NE (&c, &v);
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
