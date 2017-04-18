
#include "stdafx.h"
#include <iostream>//поток ввода вывода
#include <cstdlib>//для работы system("pause")
#include "m_geometry.h"
#include "figures.h"
using namespace std;

pointarr intercept(triangle &tr, circle &rhs);
pointarr intercept(triangle &lhs, triangle &rhs);

int main()//Главная функция
{	
	point one(2, 2), two(5, 7), three(7, 1), four(2, 6),five(4,1),six(8,6);
	triangle zero(one, two,three);
	triangle test(four, five, six);
	pointarr res = intercept(zero, test);
	/*for (const auto &x : res.result)
	{
		cout << "(" << x.get_x() << " ; " << x.get_y() << ")" << endl;
	}	*/
	system("pause");
	return 0;
}

pointarr intercept(triangle & tr, circle & rhs)
{
	pointarr res;
	int dim = 3;
	int j, k;
	for (int i = 0; i < dim; i++)
	{		
		j = i%dim;
		k = (i + 1) % dim;
		line temp(tr.get()[j], tr.get()[k]);
		res = intercept(rhs, temp);
		for (const auto &x : res.result)
		{
			cout << "(" << x.get_x() << " ; " << x.get_y() << ")" << endl;
		}
	}
	return res;
}

pointarr intercept(triangle & lhs, triangle & rhs)
{
	pointarr res;
	int dim = 3;
	int out1, out2, in1, in2;
	for (int i = 0; i < dim; i++)
	{
		out1 = i%dim;
		out2 = (i + 1) % dim;
		line out(lhs.get()[out1], lhs.get()[out2]);
		for (int j = 0; j < dim; j++)
		{
			in1 = j%dim;
			in2 = (j + 1) % dim;
			line in(rhs.get()[in1], rhs.get()[in2]);
			res = intercept(out,in);
			for (const auto &x : res.result)
			{
				cout << "(" << x.get_x() << " ; " << x.get_y() << ")" << endl;
			}
		}
	}
	return res;
}
