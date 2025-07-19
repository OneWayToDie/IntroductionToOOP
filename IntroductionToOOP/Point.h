#pragma once
#include<iostream>
using namespace std;

#define delimiter "\n-----------------------------------------------\n"

class Point;
Point operator+(const Point& left, const Point& right);
bool operator==(const Point& left, const Point& right);
bool operator!=(const Point& left, const Point& right);


class Point
{
	double x;
	double y;

public:
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);
	//constructors;

	//Point();
	//Point(double x);
	Point(double x = 0, double y = 0);
	Point(const Point& other);
	//destructor:
	~Point();
	//operators:
	Point& operator=(const Point& other);
	Point& operator++(); // Prefix increment
	Point operator++(int);	//Postfix (Suffix) increment
	// Methods:
	double distance(const Point& other)const;
	void print()const;
};