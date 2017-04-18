#pragma once
#include "mpoint.h"
class circle
{
private:
	point cent;//����� ����������
	double r;//������ ����������
public:
	circle(point A, double rad);
	circle(const circle &rhs);
	~circle() {};
	//������ ������� � ����������� ��������� ���������� (x-a)^2+(y-a)^2=R^2
	double radius() const { return r; }
	point center() const { return cent; }
	//��������������� ���������
	circle &operator=(const circle &rhs);
	friend bool operator==(const circle& lhs, const circle& rhs);
};