#include "stdafx.h"
#include "mcircle.h"

circle::circle(point A, double rad):cent(A), r(rad)
{
}

circle::circle(const circle & rhs)
{
	cent = rhs.cent;
	r = rhs.r;
}

circle & circle::operator=(const circle & rhs)
{
	if (this != &rhs)
	{
		r = rhs.radius();
		cent = rhs.center();
	}
	return *this;
}

bool operator==(const circle & lhs, const circle & rhs)
{
	if (lhs.r==rhs.r && lhs.cent==rhs.cent)//проверка равенства окружностей
	{
		return true;
	}
	else return false;
}
