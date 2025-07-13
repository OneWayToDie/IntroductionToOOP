//#include<iostream>
//using namespace std;
//
//class String;
//
//class String
//{
//public:
//	string hello/* = "Hello "*/;
//	string world/* = "World"*/;
//	string hello_world /*= "Hello world"*/ = hello + world;
//
//	//					Constructors
//	String(string hello)
//	{
//		this->hello = hello;
//		this->world = world;
//		this->hello_world = hello_world;
//		cout << "constructors1" << endl;
//	}
//	String(string hello, string world)
//	{
//		this->world = "World";
//		cout << "constructors2" << endl;
//	}
//	String(string hello, string world, string hello_world)
//	{
//		this->hello = hello;
//		this->world = world;
//		cout << "constructors3" << endl;
//	}
//
//
//	//					Methods
//	void print()
//	{
//		if ("Hello")
//			cout << hello << endl;
//		if ("World")
//			cout << world << endl;
//		if ("Hello world")
//			cout << hello << " " << world << endl;
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "");
//
//	String hello("Hello");
//	hello.print();
//	String world("World");
//	world.print();
//	String helloworld("Hello world");
//	helloworld.print();
//}



//#include<iostream>
//using namespace std;
//
//class String;
//
//class String
//{
//public:
//	string hello;
//	string world;
//	string hello_world = hello + world;
//
//	//					Constructors
//
//	String(string hello, string world)
//	{
//		this->hello = hello;
//		this->world = world;
//		cout << "constructors2" << endl;
//	}
//
//
//	//					Methods
//	void print()
//	{
//		if ("Hello")
//			cout << hello << endl;
//		if ("World")
//			cout << world << endl;
//		if ("Hello world")
//			cout << hello << " " << world << endl;
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "");
//
//	String hello("Hello", "world");
//	hello.print();
//
//}
#include<iostream>
using namespace std;

class String;
std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(String left, String right);

class String
{
	string hello;
	string world;
	string hello_world = hello + world;
public:
	
	string get_hello()const
	{
		return hello;
	}
	string get_world()const
	{
		return world;
	}
	string get_hello_world()const
	{
		return hello_world;
	}
	void set_hello(string hello)
	{
		this->hello = hello;
	}
	void set_world(string world)
	{
		this->world = world;
	}
	void set_hello_world(string hello_world)
	{
		this->hello_world = hello_world;
	}
	//					Constructors
	String()
	{
		this->hello = "Hello";
		cout << "DefaultConstructor\t" << this << endl;
	}
	String(string world)
	{
		this->world = "World";
		cout << "SingleArgumentConstructor\t" << this << endl;
	}
	String(string hello, string world)
	{
		this->hello = "Hello ";
		this->world = "world";
		cout << "Constructor\t" << this << endl;
	}

	~String()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//					Methods
	void print()
	{
		if ("Hello")cout << hello;
		if ("World")cout << world;
		cout << endl;
	}
};

//Явно не то, что вы ждёте, чёт не получилось нифига, но вывод какой нужен....... но по ощущениям - не то....
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	os << obj.get_hello() << obj.get_world();
	return os;
}
String operator+(String left, String right)
{
	return String
	(
		left.get_hello() + right.get_world()
	);
}

#define str_check
//#define ostream_check

void main()
{
	setlocale(LC_ALL, "");
#ifdef str_check
	String hello;
	hello.print();
	String world = String("world");
	world.print();
	String hello_world("Hello", "world");
	hello_world.print();
#endif
#ifdef ostream_check
	String hello_world("Hello", "world");
	cout << hello_world << endl;
#endif
}