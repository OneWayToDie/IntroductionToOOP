#include<iostream>
using namespace std;

#define delimiter "\n-----------------------------------------------\n"

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

	//constructors;
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = 0;
	//	cout << "SingleArgumentConstructor: " << this << endl;
	//	//Конструктор с одним параметром
	//}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	//destructors:
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator++() // Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)	//Postfix (Suffix) increment
	{
		Point old = *this; //сохраняем старое значение объекта
		x++;
		y++;
		return old;
	}

	// Methods:
	double distance(const Point& other)const
	{
		//this - эта точка(находим расстояние от этой точки)
		//other - та точка(до указанной точки)
		/*this->x *= 100;*/ //E0137
		/*other.x *= 100;*/ // E0137
		double x_distance = this-> x - other.x;
		double y_distance = this-> y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//sqrt() - Square Root(квадратный корень)
		return distance;
	}

	//funсtions:
	void print()const
	{
		cout << this << ": X = " << x << ",\tY = " << y << endl;
	}
};


double distance(const Point& A,const Point& B)
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

//#define STRUCT_POINT
//#define distance_check
//#define constructors_check
//#define Assignment_check
//#define arithmetical_operators_check


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
#ifdef distance_check
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "расстояние от точки 'B' до точки 'A': " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "расстояние между точками 'A' и 'B': " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "расстояние между точками 'B' и 'A': " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << sizeof(Point) << endl;
#endif
#ifdef constructors_check
	Point A; //Здесь мы просто создаём объект, и для этого вызывается конструктор по умолчанию
	A.print();
	//{
	//	//Point A;
	//	Point B;
	//	cout << "Point B существует" << endl;
	//}
	//cout << "Здесь Point B уже не существует" << endl;

	Point B = 5; //Single-argument constructor - конструктор с одним параметром
	B.print();

	Point C(7, 8); //
	C.print();

	Point D = C;
	D.print();

	Point E;	//Default constructor
	E = D;		//Assignment operator
	E.print();

#endif
#ifdef Assignment_check
	int a, b, c;

	a = b = c = 0;

	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	//Point(2,3) - Здесь мы явно вызываем конструктор, и создаем временный безымянный объект
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif
#ifdef arithmetical_operators_check
	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();

	A = B++;
	A.print();
	B.print();
#endif

	cout << (Point(2, 3) != Point(7,3)) << endl;


}

