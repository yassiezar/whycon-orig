/*
 * File name: CPosition.h
 * Date:      2005/10/25 12:49
 * Author:    
 */

#ifndef __CPOSITION_H__
#define __CPOSITION_H__

#include <whycon/common/CPoint.hpp>

namespace Whycon
{
	class CPosition : public CPoint
	{
	public:
		CPosition();
		CPosition(float x,float y,float phi);
		~CPosition();

		void set(float x,float y,float phi);

		CPosition operator +(CPosition pos);
		CPosition operator -(CPosition pos);
		CPosition operator -();
		CPosition operator /(float divisor);
		CPosition operator *(float multiplier);

		void normalizePhi();

		float phi;
	};
}

#endif

/* end of CPosition.h */
