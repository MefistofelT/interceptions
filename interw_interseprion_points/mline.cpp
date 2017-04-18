#include "stdafx.h"
#include <algorithm>
#include "mline.h"

line::line(point A, point B) :left(A), right(B)
{
	//переменные для удобства записи
	double x1 = A.get_x();
	double y1 = A.get_y();
	double x2 = B.get_x();
	double y2 = B.get_y();
	//расчет коефициентов прямой
	a = y2 - y1;
	b = -(x2 - x1);
	c = -x1*(y2 - y1) + y1*(x2 - x1);
}

line::line(double A, double B, double C):a(A),b(B),c(C)
{
}

line::line(const line & rhs)//конструктор копировани
{
	left = rhs.left;
	right = rhs.right;
	a = rhs.a;
	b = rhs.b;
	c = rhs.c;

}

bool line::in_interval(const point & A)
{
	//переменные для удобства записи
	double x1 = left.get_x();
	double y1 = left.get_y();
	double x2 = right.get_x();
	double y2 = right.get_y();
	double x = A.get_x();
	double y = A.get_y();

	double temp = std::max(x1, x2);
	x1 = std::min(x1, x2);
	x2 = temp;

	temp = std::max(y1, y2);
	y1 = std::min(y1, y2);
	y2 = temp;
	if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
	{
		return true;
	}
	return false;
}


line & line::operator=(const line  & rhs)
{
	if (this != &rhs)
	{
		left = rhs.left;
		right = rhs.right;
	}
	return *this;
}

bool operator==(const line & lhs, const line & rhs)
{
	if (lhs.a * rhs.b == lhs.b * rhs.a && lhs.b * rhs.c == lhs.c * rhs.b)//проверка равенства прямых
	{
		return true;
	}
	else return false;
}
