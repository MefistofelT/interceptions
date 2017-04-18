#pragma once
#include "mpoint.h"
class line
{
private:
	point left, right;//����� ������, ����� ��� �������� ����� �� ����� �� ������� ������
	double a, b, c;//����������� � ��������� ������ ax+by+c=0
public:
	line(point A, point B);
	line(double A,double B,double C);
	line(const line &rhs);
	~line() {};
	//��������������� �������
	bool in_interval(const point &A);
	//������ ������� � ����������� ������  ax*x+by*y+fm=0
	double ax() const { return a; }
	double by() const { return b; }
	double fm() const { return c; }
	//��������������� ���������
	line &operator=(const line &rhs);	
	friend bool operator==(const line& lhs, const line& rhs);	
};