#include"Point.h"

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

