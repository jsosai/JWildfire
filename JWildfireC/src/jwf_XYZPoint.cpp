/*
  JWildfireC - an external C-based fractal-flame-renderer for JWildfire
  Copyright (C) 2012 Andreas Maschke

  This is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser
  General Public License as published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) any later version.

  This software is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
  even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License along with this software;
  if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
  02110-1301 USA, or see the FSF site: http://www.fsf.org.
*/

#include "math.h"
#include "jwf_Constants.h"
#include "jwf_XYZPoint.h"

XYZPoint::XYZPoint() {
  x=y=z=color=0.0;
   rgbColor=0;
	 redColor=greenColor=blueColor=0.0;
	 validSumsq= validSqrt=  validAtan=	 validAtanYX=  validSinA=	  validCosA=FALSE;
}

void XYZPoint::assign(XYZPoint *p) {
	x = p->x;
	y = p->y;
	z = p->z;
	color = p->color;
	sumsq = p->sumsq;
	validSumsq = p->validSumsq;
	sqrt = p->sqrt;
	validSqrt = p->validSqrt;
	atan = p->atan;
	validAtan = p->validAtan;
	atanYX = p->atanYX;
	validAtanYX = p->validAtanYX;
	sinA = p->sinA;
	validSinA = p->validSinA;
	cosA = p->cosA;
	validCosA = p->validCosA;
	rgbColor = p->rgbColor;
	redColor = p->redColor;
	greenColor = p->greenColor;
	blueColor = p->blueColor;
}

void XYZPoint::invalidate() {
    validSumsq = validSqrt = validAtan = validAtanYX = validSinA = validCosA = FALSE;
}

void XYZPoint::clear() {
    rgbColor = FALSE;
    redColor = greenColor = blueColor = 0.0f;
    x = y = z = color = 0.0f;
    sumsq = sqrt = atan = atanYX = sinA = cosA = 0.0f;
    validSumsq = validSqrt = validAtan = validAtanYX = validSinA = validCosA = FALSE;
}

float XYZPoint::getPrecalcSumsq() {
    if (validSumsq==FALSE) {
      sumsq = x * x + y * y;
      validSumsq = TRUE;
    }
    return sumsq;
}

float XYZPoint::getPrecalcSqrt() {
    if (validSqrt==FALSE) {
      sqrt = sqrtf(x * x + y * y) + EPSILON;
      validSqrt = TRUE;
    }
    return sqrt;
}

float XYZPoint::getPrecalcAtan() {
    if (validAtan==FALSE) {
      atan = atan2f(x, y);
      validAtan = TRUE;
    }
    return atan;
}

float XYZPoint::getPrecalcAtanYX() {
    if (validAtanYX==FALSE) {
      atanYX = atan2f(y, x);
      validAtanYX = TRUE;
    }
    return atanYX;
}

  float XYZPoint::getPrecalcSinA() {
    if (validSinA==FALSE) {
      sinA = x / getPrecalcSqrt();
      validSinA = TRUE;
    }
    return sinA;
  }

  float XYZPoint::getPrecalcCosA() {
    if (validCosA==FALSE) {
      cosA = y / getPrecalcSqrt();
      validCosA = TRUE;
    }
    return cosA;
  }

  bool XYZPoint::isEqual(XYZPoint *pSrc) {
    if (fabs(x - pSrc->x) > EPSILON || fabs(y - pSrc->y) > EPSILON ||
        fabs(z - pSrc->z) > EPSILON || fabs(color - pSrc->color) > EPSILON ||
        rgbColor != pSrc->rgbColor || fabs(redColor - pSrc->redColor) > EPSILON ||
        fabs(greenColor - pSrc->greenColor) > EPSILON || fabs(blueColor - pSrc->blueColor) > EPSILON) {
      return FALSE;
    }
    return TRUE;
  }

