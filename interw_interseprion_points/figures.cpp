#include "stdafx.h"
#include "figures.h"

triangle::triangle(point A, point B, point C)
{
	vertices = new point[3];
	vertices[0] = A;
	vertices[1] = B;
	vertices[2] = C;
}

triangle::triangle(const triangle & rhs)
{
	vertices[0] = rhs.vertices[0];
	vertices[1] = rhs.vertices[1];
	vertices[2] = rhs.vertices[2];
}

triangle::~triangle()
{
	delete[]vertices;
}

triangle & triangle::operator=(triangle const & rhs)
{
	if (this != &rhs)
	{
		vertices[0] = rhs.vertices[0];
		vertices[1] = rhs.vertices[1];
		vertices[2] = rhs.vertices[2];
	}
	return *this;
}

bool operator==(const triangle & lhs, const triangle & rhs)
{
	int dim = 3;
	int flag = 0;
	for (int i = 0; i < dim; i++)
	{
		if (lhs.vertices[i] == rhs.vertices[i])
		{
			flag++;
		}
	}
	if (flag == dim) return true;
	return false;
}
