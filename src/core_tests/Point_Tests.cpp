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
