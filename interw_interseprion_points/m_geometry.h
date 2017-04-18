#pragma once
#include <deque>//дек для динамического результата
#include "mline.h"//Класс точкии прямой
#include "mcircle.h"//класс окружности
struct solution
{
	std::deque<double> result;
};

struct pointarr
{
	std::deque<point> result;
};

solution quadr_equation(double a, double b, double c);//решение квадратного уравнения
pointarr intercept(line &lhs, line &rhs);//Пересечение 2  прямых
pointarr intercept(circle &lhs, line &rhs);//Пересечение прямой и круга
pointarr intercept(circle &lhs, circle &rhs);//Пересечение 2  кругов