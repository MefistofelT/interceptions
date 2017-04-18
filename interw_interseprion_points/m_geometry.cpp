#include "stdafx.h"
#include "m_geometry.h"
//���������� ������� ����������� ���������
solution quadr_equation(double a, double b, double c)
{
	solution res;
	// ���� ����� ����������� ���������
	if (a == 0) // ��������� �� ����������
	{
		if (b == 0) // ��������� �� ��������
		{
			if (c == 0) // ����������� ��������� �������
			{

			}
			else //�� ����� �������
			{

			}
		}
		else // ��������� ��������
		{
			double x = -c / b;
			res.result.push_back(x);
		}
	}
	else // ��������� ����������
	{
		double disc = b * b - 4 * a * c; //��������� ������������
		if (disc > 0) //��������� ����� �������������� �����
		{
			double x1 = (-b - sqrt(disc)) / (2 * a);   //��������� ������ ������
			double x2 = (-b + sqrt(disc)) / (2 * a);  //��������� ������ ������
			res.result.push_back(x1);
			res.result.push_back(x2);

		}
		if (disc == 0)//��������� ����� ������������ ������
		{
			double x = -b / (2 * a);
			res.result.push_back(x);

		}
		else //��������� ����� ����������� �����, ��� ������� ����� ��������� �������� � ������ �����
		{

		}
	}
	return res;//������� ����������
}

pointarr intercept(line & lhs, line & rhs)
{
	pointarr res;
	if (lhs == rhs)
	{
		//������ ����� ������ ���������

	}
	else if (lhs.fm() != rhs.fm() && lhs.ax()*rhs.by() == rhs.ax()*lhs.by())
	{
		//������ ����� ������ �����������

	}
	else
	{
		double x, y;//�����. ����� ����������
		double a = rhs.ax(), b = rhs.by(), c = rhs.fm();
		double a1 = lhs.ax(), b1 = lhs.by(), c1 = lhs.fm();
		/*� ����������� ���� �������� ������������
		������� ������� ��������� �� ���� ������*/
		x = (b*c1 - b1*c) / (a*b1 - a1*b);
		y = -1 * (a*c1 - a1*c) / (a*b1 - a1*b);
		point ipc(x, y);
		if (lhs.in_interval(ipc) && rhs.in_interval(ipc))
			res.result.push_back(ipc);
	}
	return res;
}

pointarr intercept(circle & lhs, line & rhs)
{
	pointarr res;
	bool inverse = false;//���� ��������, ��� ���������� ��������� �������������� � ������������ ������
						 //��������� �����
	double a = lhs.center().get_x();
	double bc = lhs.center().get_y();
	double rad = lhs.radius();
	double A, B, C;//��������� ����� � ��������� ������ ������� �������
	A = -2 * a;
	B = -2 * bc;
	C = a*a + bc*bc - rad*rad;
	//��������� � ��������� ������ y=kx+b
	double k = -rhs.ax() / rhs.by();
	double b = -rhs.fm() / rhs.by();
	//����� ��������� ���������� ������������ y=kx+b � ��������� ����������
	//����������� ����������� ��������� a1,b1,c1
	//std::cout << "k: " << k << " b: " << b <<"DEBUG" <<std::endl; ������ �������
	double a1, b1, c1;
	if (rhs.by() != 0)//���� ������ �� ������������ ������ ������� ������������ �
	{
		a1 = 1 + k*k;
		b1 = 2 * k*b + A + B*k;
		c1 = b*b + B*b + C;
	}
	else //���� ������ ������������ ������ ������� ������������ �
	{
		inverse = true;
		k = -rhs.by() / rhs.ax();
		b = -rhs.fm() / rhs.ax();
		a1 = 1 + k*k;
		b1 = 2 * k*b + B + A*k;
		c1 = b*b + A*b + C;
	}
	solution r = quadr_equation(a1, b1, c1);
	if (!r.result.empty())//���� ������� �� ������
	{
		double y;
		for (const auto &x : r.result)//��� ���� ��������� �������
		{
			if (inverse)//���� ������ ������������ �� � � � ����� �������� �������
			{
				y = k*x + b;//��������� ��������
				point ipc(y, x);
				if (rhs.in_interval(ipc))//���� ����� �������� � �������
					res.result.push_back(ipc);//��������� ����� � ���������
			}
			else
			{
				y = k*x + b;//��������� ��������
				point ipc(x, y);
				if (rhs.in_interval(ipc))//���� ����� �������� � �������
					res.result.push_back(ipc);//��������� ����� � ���������
			}
		}
	}
	return res;

}

pointarr intercept(circle & lhs, circle & rhs)
{
	pointarr res;
	if (lhs == rhs)
	{
		//������ ���� ���������� ���������
	}
	else//���� ���������� �� ���������
	{
		//���������� ��������� ������ ����������
		double a = lhs.center().get_x();
		double bc = lhs.center().get_y();
		double rad = lhs.radius();
		double A, B, C;//��������� ������� ����� � ��������� ������ ������� �������
		A = -2 * a;
		B = -2 * bc;
		C = a*a + bc*bc - rad*rad;
		//���������� ��������� ������ ����������
		a = rhs.center().get_x();
		bc = rhs.center().get_y();
		rad = rhs.radius();
		double A1, B1, C1;//��������� ������� ����� � ��������� ������ ������� �������
		A1 = -2 * a;
		B1 = -2 * bc;
		C1 = a*a + bc*bc - rad*rad;

		line help(A - A1, B - B1, C - C1);//������� �� ������� ��������� ������ �������� � ������� ����������� ������ � ���������� 
		res = intercept(rhs, help);//��������� ���������
	}
	return res;
}
