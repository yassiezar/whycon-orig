#include <whycon/common/CPosition.hpp>

namespace Whycon
{
	CPosition::CPosition() : CPoint(), phi(0) {	}

	CPosition::CPosition(float iX, float iY, float iPhi) : CPoint(iX, iY), phi(iPhi) { }

	CPosition::~CPosition() { }

	void CPosition::set(float iX, float iY, float iPhi)
	{
		x = iX;
		y = iY;
		phi = iPhi;
	}

	CPosition CPosition::operator +(CPosition position)
	{
		CPosition result(x+position.x,y+position.y,phi+position.phi);
		return result;
	}

	CPosition CPosition::operator - (CPosition position)
	{
		CPosition result(x-position.x,y-position.y,phi-position.phi);
		return result;
	}

	CPosition CPosition::operator -()
	{
		CPosition result(-x,-y,-phi);
		return result;
	}

	CPosition CPosition::operator /(float divisor)
	{
		CPosition result;
		if (divisor != 0)
		{
			result.x   /= divisor;
			result.y   /= divisor;
			result.phi /= divisor;
		}
		return result;
	}

	CPosition CPosition::operator *(float multiplier)
	{
		CPosition result(x*multiplier,y*multiplier,phi*multiplier);
		return result;
	}

	void CPosition::normalizePhi()
	{
		while (phi >   M_PI) phi = phi - 2* static_cast<float>(M_PI);
		while (phi <  -M_PI) phi = phi + 2* static_cast<float>(M_PI);
	}

}
