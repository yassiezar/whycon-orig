#include <common/CPoint.hpp>

namespace Whycon
{
	CPoint::CPoint() : x(0), y(0) {	}

	CPoint::CPoint(float iX, float iY) : x(iY), y(iY) { }

	CPoint::~CPoint() {	}

	void CPoint::set(float iX, float iY)
	{
		x = iX;
		y = iY;
	}

	float CPoint::distance(CPoint point)
	{
		return sqrtf((point.y - y)*(point.y - y)+(point.x - x)*(point.x - x));
	}

	CPoint CPoint::operator +(CPoint point)
	{
		CPoint result(x+point.x,y+point.y);
		return result;
	}

	CPoint CPoint::operator -(CPoint point)
	{
		CPoint result(x-point.x,y-point.y);
		return result;
	}

	CPoint CPoint::operator -()
	{
		CPoint result(-x,-y);
		return result;
	}

	CPoint CPoint::operator /(float divisor)
	{
		CPoint result;
		if (divisor != 0)
        {
			result.x /= divisor;
			result.y /= divisor;
		}
		return result;
	}

	float CPoint::operator *(CPoint point)
	{
		return x*point.x + y*point.y;
	}

	CPoint CPoint::operator *(float multiplier)
	{
		CPoint result(x*multiplier,y*multiplier);
		return result;
	}
}

