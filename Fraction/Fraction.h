#pragma once
#include<iostream>
using namespace std;

class Fraction; //объ€вление класса
Fraction operator*(Fraction left, Fraction right); //объ€вление оператора
Fraction operator/(const Fraction& left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, const Fraction& obj);

class Fraction	// ќписание класса
{
	int integer; //÷ела€ часть
	int numerator; //„ислитель
	int denominator; //«наменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//		Constructors:
	Fraction();
	Fraction(double decimal);
	explicit Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	//		Operators:
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	//Incremento/Decremento:
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	//					Type-cast operators:
	explicit operator int()const;
	explicit operator double()const;
	//		Methods:
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();
	void print()const;
};
