#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
	
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Methods:
	double distance(Point other)
	{
		//this - эта точка(находим расстояние от этой точки)
		//other - та точка(до указанной точки)

		double x_distance = this-> x - other.x;
		double y_distance = this-> y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//sqrt() - Square Root(квадратный корень)
		return distance;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}


//#define STRUCT_POINT



void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a; // Обявление переменной 'a' типа 'int';
	Point A; // Обявление переменной 'A' типа 'Point';
			 // Создание объекта 'A' структуры 'Point';
			 // Создание экземпляра 'A' структуры 'Point';
			 // 'A' is instance of struct 'Point'
			 // Instantiate - создать объект.
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT


	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << "расстояние от точки 'B' до точки 'A': " << A.distance(B) << endl;

	cout << "расстояние между точками 'A' и 'B': " << distance(A, B) << endl;
	cout << "расстояние между точками 'B' и 'A': " << distance(A, B) << endl;


}

