#pragma once
class point
{
private:
	double x;//���������� � �����
	double y;//���������� � �����
public:
	//������������
	point(double ab = 0, double ord = 0) :x(ab), y(ord) {};
	point(const point &rhs);
	~point() {};
	//������ �������
	void set_x(double coord) { x = coord; }
	void set_y(double coord) { y = coord; }
	double get_x() const { return x; }
	double get_y() const { return y; }
	//��������������� ���������
	point &operator=(point const &rhs);
	friend bool operator==(const point & lhs, const point & rhs);

};