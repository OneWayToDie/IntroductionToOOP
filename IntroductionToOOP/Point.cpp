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
//	//Конструктор с одним параметром
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
	Point old = *this; //сохраняем старое значение объекта
	x++;
	y++;
	return old;
}
//							Methods:
double Point::distance(const Point& other)const
{
	//this - эта точка(находим расстояние от этой точки)
	//other - та точка(до указанной точки)
	/*this->x *= 100;*/ //E0137
	/*other.x *= 100;*/ // E0137
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	//sqrt() - Square Root(квадратный корень)
	return distance;
}
void Point::print()const
{
	cout << this << ": X = " << x << ",\tY = " << y << endl;
}