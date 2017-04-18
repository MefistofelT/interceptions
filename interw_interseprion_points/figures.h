#pragma once
#include "mpoint.h"
class triangle
{
private:
	point *vertices;//������� ������������	
public:
	triangle(point A, point B, point C);
	triangle(const triangle &rhs);
	~triangle();
	//������ �������
	point *get() const { return vertices; };
	//��������������� ���������
	triangle &operator=(triangle const &rhs);
	friend bool operator==(const triangle & lhs, const triangle & rhs);
};