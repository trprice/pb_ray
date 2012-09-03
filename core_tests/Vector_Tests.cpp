/*
 *  Vector_Tests.cpp
 *  p_ray
 *
 *  Created by Taylor Price on 8/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Vector_Tests.h"

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