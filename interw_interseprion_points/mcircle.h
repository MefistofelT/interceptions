#pragma once
#include "mpoint.h"
class circle
{
private:
	point cent;//центр окружности
	double r;//радиус окружности
public:
	circle(point A, double rad);
	circle(const circle &rhs);
	~circle() {};
	//методы доступа к коефицентам уравнения окружности (x-a)^2+(y-a)^2=R^2
	double radius() const { return r; }
	point center() const { return cent; }
	//перерегруженные операторы
	circle &operator=(const circle &rhs);
	friend bool operator==(const circle& lhs, const circle& rhs);
};