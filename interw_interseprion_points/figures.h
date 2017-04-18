#pragma once
#include "mpoint.h"
class triangle
{
private:
	point *vertices;//вершины треугольника	
public:
	triangle(point A, point B, point C);
	triangle(const triangle &rhs);
	~triangle();
	//методы доступа
	point *get() const { return vertices; };
	//перерегруженные операторы
	triangle &operator=(triangle const &rhs);
	friend bool operator==(const triangle & lhs, const triangle & rhs);
};