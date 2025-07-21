#include"Point.h"
double Point::get_x()const
{
	return x;
}
double Point::get_y()const
{
	return y;
}
void Point::set_x(double x)
{
	this->x = x;
}
void Point::set_y(double y)
{
	this->y = y;
}
//							constructors;
//Point::Point() :x(0), y(0)
//{
//	x = y = 0;
//	cout << "DefaultConstructor:\t" << this << endl;
//}
//Point::Point(double x) :x(x), y(0)
//{
//	this->x = x;
//	this->y = 0;
//	cout << "SingleArgumentConstructor: " << this << endl;
//	//����������� � ����� ����������
//}
Point::Point(double x, double y) :x(x), y(y)
{
	//this->x = x;
	//this->y = y;
	cout << "Constructor:\t\t" << this << endl;
}
Point::Point(const Point& other) :x(other.x), y(other.y)
{
	//this->x = other.x;
	//this->y = other.y;
	cout << "CopyConstructor:\t" << this << endl;
}
//							destructor:
Point::~Point()
{
	cout << "Destructor:\t\t" << this << endl;
}
//							operators:
Point& Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
Point& Point::operator++() // Prefix increment
{
	x++;
	y++;
	return *this;
}
Point Point::operator++(int)	//Postfix (Suffix) increment
{
	Point old = *this; //��������� ������ �������� �������
	x++;
	y++;
	return old;
}
//							Methods:
double Point::distance(const Point& other)const
{
	//this - ��� �����(������� ���������� �� ���� �����)
	//other - �� �����(�� ��������� �����)
	/*this->x *= 100;*/ //E0137
	/*other.x *= 100;*/ // E0137
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	//sqrt() - Square Root(���������� ������)
	return distance;
}
void Point::print()const
{
	cout << this << ": X = " << x << ",\tY = " << y << endl;
}

double distance(const Point& A, const Point& B)
{
	/*A.set_x(A.get_x() *= 100);*/
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}