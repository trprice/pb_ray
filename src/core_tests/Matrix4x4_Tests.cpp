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
 *  File Name: Matrix4x4_Tests.cpp
 *
 *  Purpose: Contain the tests for the BBox class.
 *
 *  Creation Date: 29-01-2014
 *
 *  Last Modified:
 */

#include "Matrix4x4_Tests.h"

// Test no-args constructor
TEST_F(Matrix4x4Test, NoArgsConstructorWorks) {
    Matrix4x4 m;

    // Test for the identity matrix
    EXPECT_EQ (1, m.m[0][0]);
    EXPECT_EQ (1, m.m[1][1]);
    EXPECT_EQ (1, m.m[2][2]);
    EXPECT_EQ (1, m.m[3][3]);

    EXPECT_EQ (0, m.m[0][1]);
    EXPECT_EQ (0, m.m[0][2]);
    EXPECT_EQ (0, m.m[0][3]);

    EXPECT_EQ (0, m.m[1][0]);
    EXPECT_EQ (0, m.m[1][2]);
    EXPECT_EQ (0, m.m[1][3]);

    EXPECT_EQ (0, m.m[2][0]);
    EXPECT_EQ (0, m.m[2][1]);
    EXPECT_EQ (0, m.m[2][3]);

    EXPECT_EQ (0, m.m[3][0]);
    EXPECT_EQ (0, m.m[3][1]);
    EXPECT_EQ (0, m.m[3][2]);
}

// Test args constructor
TEST_F(Matrix4x4Test, MatrixConstructorWorks) {
    float f[4][4] = {{0, 0, 0, 0},
                     {1, 1, 1, 1},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    Matrix4x4 m (f);

    EXPECT_EQ (0, m.m[0][0]);
    EXPECT_EQ (0, m.m[0][1]);
    EXPECT_EQ (0, m.m[0][2]);
    EXPECT_EQ (0, m.m[0][3]);

    EXPECT_EQ (1, m.m[1][0]);
    EXPECT_EQ (1, m.m[1][1]);
    EXPECT_EQ (1, m.m[1][2]);
    EXPECT_EQ (1, m.m[1][3]);

    EXPECT_EQ (0, m.m[2][0]);
    EXPECT_EQ (0, m.m[2][1]);
    EXPECT_EQ (0, m.m[2][2]);
    EXPECT_EQ (0, m.m[2][3]);

    EXPECT_EQ (0, m.m[3][0]);
    EXPECT_EQ (0, m.m[3][1]);
    EXPECT_EQ (0, m.m[3][2]);
    EXPECT_EQ (0, m.m[3][3]);
}

// Test Array constructor
TEST_F(Matrix4x4Test, ArrrayConstructorWorks) {
	std::array <std::array <float, 4>, 4> f { { { 0, 0, 0, 0 },
	{ 1, 1, 1, 1 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 } } };

	Matrix4x4 m(f);

	EXPECT_EQ(0, m.m[0][0]);
	EXPECT_EQ(0, m.m[0][1]);
	EXPECT_EQ(0, m.m[0][2]);
	EXPECT_EQ(0, m.m[0][3]);

	EXPECT_EQ(1, m.m[1][0]);
	EXPECT_EQ(1, m.m[1][1]);
	EXPECT_EQ(1, m.m[1][2]);
	EXPECT_EQ(1, m.m[1][3]);

	EXPECT_EQ(0, m.m[2][0]);
	EXPECT_EQ(0, m.m[2][1]);
	EXPECT_EQ(0, m.m[2][2]);
	EXPECT_EQ(0, m.m[2][3]);

	EXPECT_EQ(0, m.m[3][0]);
	EXPECT_EQ(0, m.m[3][1]);
	EXPECT_EQ(0, m.m[3][2]);
	EXPECT_EQ(0, m.m[3][3]);
}

TEST_F(Matrix4x4Test, ArgsConstructorWorks) {
    Matrix4x4 m (0, 0, 0, 0,
                 1, 1, 1, 1,
                 0, 0, 0, 0,
                 0, 0, 0, 0);

    EXPECT_EQ (0, m.m[0][0]);
    EXPECT_EQ (0, m.m[0][1]);
    EXPECT_EQ (0, m.m[0][2]);
    EXPECT_EQ (0, m.m[0][3]);

    EXPECT_EQ (1, m.m[1][0]);
    EXPECT_EQ (1, m.m[1][1]);
    EXPECT_EQ (1, m.m[1][2]);
    EXPECT_EQ (1, m.m[1][3]);

    EXPECT_EQ (0, m.m[2][0]);
    EXPECT_EQ (0, m.m[2][1]);
    EXPECT_EQ (0, m.m[2][2]);
    EXPECT_EQ (0, m.m[2][3]);

    EXPECT_EQ (0, m.m[3][0]);
    EXPECT_EQ (0, m.m[3][1]);
    EXPECT_EQ (0, m.m[3][2]);
    EXPECT_EQ (0, m.m[3][3]);
}

TEST_F(Matrix4x4Test, OperatorEqualEqualTrue) {
    Matrix4x4 m1, m2;

    ASSERT_TRUE (m1 == m2);
}

TEST_F(Matrix4x4Test, OperatorEqualEqualFalse) {
    Matrix4x4 m1;
    Matrix4x4 m2 (0, 0, 0, 0,
                 1, 1, 1, 1,
                 0, 0, 0, 0,
                 0, 0, 0, 0);

    ASSERT_FALSE (m1 == m2);
}

TEST_F(Matrix4x4Test, OperatorNotEqualFalse) {
    Matrix4x4 m1, m2;

    ASSERT_FALSE (m1 != m2);
}

TEST_F(Matrix4x4Test, OperatorNotEqualTrue) {
    Matrix4x4 m1;
    Matrix4x4 m2 (0, 0, 0, 0,
                 1, 1, 1, 1,
                 0, 0, 0, 0,
                 0, 0, 0, 0);

    ASSERT_TRUE (m1 != m2);
}

TEST_F(Matrix4x4Test, MulWorks) {
    Matrix4x4 m1 (1, 1, 1, 1,
                  0, 0, 0, 0,
                  0, 0, 0, 0,
                  0, 0, 0, 0);
    Matrix4x4 m2 (2, 0, 0, 0,
                  2, 0, 0, 0,
                  2, 0, 0, 0,
                  2, 0, 0, 0);

    Matrix4x4 r = Matrix4x4::Mul (m1, m2);

    EXPECT_EQ (8, r.m[0][0]);
    EXPECT_EQ (0, r.m[0][1]);
    EXPECT_EQ (0, r.m[0][2]);
    EXPECT_EQ (0, r.m[0][3]);

    EXPECT_EQ (0, r.m[1][0]);
    EXPECT_EQ (0, r.m[1][1]);
    EXPECT_EQ (0, r.m[1][2]);
    EXPECT_EQ (0, r.m[1][3]);

    EXPECT_EQ (0, r.m[2][0]);
    EXPECT_EQ (0, r.m[2][1]);
    EXPECT_EQ (0, r.m[2][2]);
    EXPECT_EQ (0, r.m[2][3]);

    EXPECT_EQ (0, r.m[3][0]);
    EXPECT_EQ (0, r.m[3][1]);
    EXPECT_EQ (0, r.m[3][2]);
    EXPECT_EQ (0, r.m[3][3]);
}

TEST_F(Matrix4x4Test, TransposeWorks) {
    Matrix4x4 m1 (0, 0, 0, 0,
                 1, 1, 1, 1,
                 0, 0, 0, 0,
                 0, 0, 0, 0);

    Matrix4x4 m2 = Transpose(m1);

    EXPECT_EQ (0, m2.m[0][0]);
    EXPECT_EQ (1, m2.m[0][1]);
    EXPECT_EQ (0, m2.m[0][2]);
    EXPECT_EQ (0, m2.m[0][3]);

    EXPECT_EQ (0, m2.m[1][0]);
    EXPECT_EQ (1, m2.m[1][1]);
    EXPECT_EQ (0, m2.m[1][2]);
    EXPECT_EQ (0, m2.m[1][3]);

    EXPECT_EQ (0, m2.m[2][0]);
    EXPECT_EQ (1, m2.m[2][1]);
    EXPECT_EQ (0, m2.m[2][2]);
    EXPECT_EQ (0, m2.m[2][3]);

    EXPECT_EQ (0, m2.m[3][0]);
    EXPECT_EQ (1, m2.m[3][1]);
    EXPECT_EQ (0, m2.m[3][2]);
    EXPECT_EQ (0, m2.m[3][3]);
}
