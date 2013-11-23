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
 *  File Name: Geometry.cpp
 *
 *  Purpose:
 *
 *  Creation Date: 8/9/12
 *
 *  Last Modified: Thu 25 Jul 2013 05:11:41 PM PDT
 */

#include "Geometry.h"


////////////////////
// BBox Methods
////////////////////
BBox Union (const BBox &b, const Point &p) {
    BBox ret = b;

    ret.pMin.x = min (b.pMin.x, p.x);
    ret.pMin.y = min (b.pMin.y, p.y);
    ret.pMin.z = min (b.pMin.z, p.z);

    ret.pMax.x = max (b.pMax.x, p.x);
    ret.pMax.y = max (b.pMax.y, p.y);
    ret.pMax.z = max (b.pMax.z, p.z);

    return ret;
}


BBox Union (const BBox &b1, const BBox &b2) {
    BBox ret;

    ret.pMin.x = min (b1.pMin.x, b2.pMin.x);
    ret.pMin.y = min (b1.pMin.y, b2.pMin.y);
    ret.pMin.z = min (b1.pMin.z, b2.pMin.z);

    ret.pMax.x = max (b1.pMax.x, b2.pMax.x);
    ret.pMax.y = max (b1.pMax.y, b2.pMax.y);
    ret.pMax.z = max (b1.pMax.z, b2.pMax.z);

    return ret;
}

void BBox::BoundingSphere (Point *c, float *rad) const {
    *c = pMin * .5f + pMax * .5f;
    *rad = Inside (*c) ? Distance (*c, pMax) : 0.f;
}
