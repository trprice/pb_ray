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
 *  File Name: transform.h
 *
 *  Purpose: Define classes and structures to perform translations.
 *
 *  Creation Date: 16-01-2014
 */


////////////////////
// struct: Matrix4x4
//
// Purpose:
//      Provide a transformation matrix and corresponding functinoality.
//
// Notes:
//      This is setup as a struct in the book.
//          - To my understanding the only significant difference between a
//            struct and a class is the default access level.
//              - A struct's members are public by default whereas a classes
//                are private.
//          - It is also my understanding that in the context of C++ where
//            classes are used to make objects that can be acted upon with
//            their member functions, structs should be reserved for POD types
//            (plain old data) that simply needs organization and no other
//            functionality.
////////////////////
