#pragma once
#include <deque>//��� ��� ������������� ����������
#include "mline.h"//����� ������ ������
#include "mcircle.h"//����� ����������
struct solution
{
	std::deque<double> result;
};

struct pointarr
{
	std::deque<point> result;
};

solution quadr_equation(double a, double b, double c);//������� ����������� ���������
pointarr intercept(line &lhs, line &rhs);//����������� 2  ������
pointarr intercept(circle &lhs, line &rhs);//����������� ������ � �����
pointarr intercept(circle &lhs, circle &rhs);//����������� 2  ������