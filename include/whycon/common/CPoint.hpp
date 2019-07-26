/*
 * File name: CPoint.h
 * Date:      2005/10/25 12:49
 * Author:    
 */

#ifndef __CPOINT_H__
#define __CPOINT_H__

#include <cmath>

namespace Whycon
{
	class CPoint
	{
	public:
		CPoint();
		CPoint(float, float);
		~CPoint();

		void set(float, float);

		float distance(CPoint);

		CPoint operator +(CPoint);
		CPoint operator -(CPoint);
		CPoint operator -();
		CPoint operator /(float);
		CPoint operator *(float);
		float operator *(CPoint);
		float x;
		float y;
	};
}

#endif

/* end of CPoint.h */
