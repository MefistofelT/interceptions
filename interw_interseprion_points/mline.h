#pragma once
#include "mpoint.h"
class line
{
private:
	point left, right;//“очки пр€мой, нужны дл€ проверки лежит ли точка на отрезке пр€мой
	double a, b, c;//коефициенты в уравнении пр€мой ax+by+c=0
public:
	line(point A, point B);
	line(double A,double B,double C);
	line(const line &rhs);
	~line() {};
	//вспомогательные функции
	bool in_interval(const point &A);
	//методы доступа к коефицентам пр€мой  ax*x+by*y+fm=0
	double ax() const { return a; }
	double by() const { return b; }
	double fm() const { return c; }
	//перерегруженные операторы
	line &operator=(const line &rhs);	
	friend bool operator==(const line& lhs, const line& rhs);	
};