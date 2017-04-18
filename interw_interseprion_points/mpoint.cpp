#include "stdafx.h"
#include "mpoint.h"
point::point(const point & rhs)
{
	x = rhs.get_x();
	y = rhs.get_y();
}

point & point::operator=(point const & rhs)
{
	if (this != &rhs)
	{
		x = rhs.get_x();
		y = rhs.get_y();
	}
	return *this;

}

bool operator==(const point & lhs,const point & rhs)
{
	if (lhs.x == rhs.x && lhs.y == rhs.y)
	{
		return true;
	}
	return false;
}