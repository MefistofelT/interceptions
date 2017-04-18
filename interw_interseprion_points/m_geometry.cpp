#include "stdafx.h"
#include "m_geometry.h"
//реализация решения квадратного уравнения
solution quadr_equation(double a, double b, double c)
{
	solution res;
	// ищем корни квадратного уравнения
	if (a == 0) // уравнение не квадратное
	{
		if (b == 0) // уравнение не линейное
		{
			if (c == 0) // бесконечное множество решений
			{

			}
			else //не имеет решения
			{

			}
		}
		else // уравнение линейное
		{
			double x = -c / b;
			res.result.push_back(x);
		}
	}
	else // уравнение квадратное
	{
		double disc = b * b - 4 * a * c; //вычисляем дискриминант
		if (disc > 0) //уравнение имеет действительные корни
		{
			double x1 = (-b - sqrt(disc)) / (2 * a);   //вычисляем первый корень
			double x2 = (-b + sqrt(disc)) / (2 * a);  //вычисляем второй корень
			res.result.push_back(x1);
			res.result.push_back(x2);

		}
		if (disc == 0)//уравнение имеет единственный корень
		{
			double x = -b / (2 * a);
			res.result.push_back(x);

		}
		else //уравнение имеет комплексные корни, при желании можно посчитать реальную и мнимую части
		{

		}
	}
	return res;//возврат результата
}

pointarr intercept(line & lhs, line & rhs)
{
	pointarr res;
	if (lhs == rhs)
	{
		//случай когда прямые совпадают

	}
	else if (lhs.fm() != rhs.fm() && lhs.ax()*rhs.by() == rhs.ax()*lhs.by())
	{
		//случай когда прямые паралельные

	}
	else
	{
		double x, y;//коорд. точки результата
		double a = rhs.ax(), b = rhs.by(), c = rhs.fm();
		double a1 = lhs.ax(), b1 = lhs.by(), c1 = lhs.fm();
		/*в приведенных ниже формулах используется
		решение системы уравнений из двух прямых*/
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
	bool inverse = false;//флаг инверсии, для правильной обработки горизонтальных и вертикальных прямых
						 //параметры круга
	double a = lhs.center().get_x();
	double bc = lhs.center().get_y();
	double rad = lhs.radius();
	double A, B, C;//параметры круга в уравнении кривой второго порядка
	A = -2 * a;
	B = -2 * bc;
	C = a*a + bc*bc - rad*rad;
	//параметры в уравнении прямой y=kx+b
	double k = -rhs.ax() / rhs.by();
	double b = -rhs.fm() / rhs.by();
	//решим уравнение полученное подстановкой y=kx+b в уравнение окружности
	//коефициенты квадратного уравнения a1,b1,c1
	//std::cout << "k: " << k << " b: " << b <<"DEBUG" <<std::endl; СТРОКА ОТЛАДКИ
	double a1, b1, c1;
	if (rhs.by() != 0)//если прямая не вертикальная решаем систему относительно у
	{
		a1 = 1 + k*k;
		b1 = 2 * k*b + A + B*k;
		c1 = b*b + B*b + C;
	}
	else //если прямая вертикальная решаем систему относительно х
	{
		inverse = true;
		k = -rhs.by() / rhs.ax();
		b = -rhs.fm() / rhs.ax();
		a1 = 1 + k*k;
		b1 = 2 * k*b + B + A*k;
		c1 = b*b + A*b + C;
	}
	solution r = quadr_equation(a1, b1, c1);
	if (!r.result.empty())//если решение не пустое
	{
		double y;
		for (const auto &x : r.result)//для всех элементов решения
		{
			if (inverse)//если прямая вертикальная то у и х нужно изменить местами
			{
				y = k*x + b;//вычисляем абсциссу
				point ipc(y, x);
				if (rhs.in_interval(ipc))//если точка попадает в отрезок
					res.result.push_back(ipc);//добавляем точку в результат
			}
			else
			{
				y = k*x + b;//вычисляем ординату
				point ipc(x, y);
				if (rhs.in_interval(ipc))//если точка попадает в отрезок
					res.result.push_back(ipc);//добавляем точку в результат
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
		//случай если окружности совпадают
	}
	else//если окружности не совпадают
	{
		//Определяем параметры первой окружности
		double a = lhs.center().get_x();
		double bc = lhs.center().get_y();
		double rad = lhs.radius();
		double A, B, C;//параметры первого круга в уравнении кривой второго порядка
		A = -2 * a;
		B = -2 * bc;
		C = a*a + bc*bc - rad*rad;
		//Определяем параметры второй окружности
		a = rhs.center().get_x();
		bc = rhs.center().get_y();
		rad = rhs.radius();
		double A1, B1, C1;//параметры второго круга в уравнении кривой второго порядка
		A1 = -2 * a;
		B1 = -2 * bc;
		C1 = a*a + bc*bc - rad*rad;

		line help(A - A1, B - B1, C - C1);//отнимая от первого уравнения второе приходим к решению пересечения прямой и окружности 
		res = intercept(rhs, help);//вычисляем результат
	}
	return res;
}
