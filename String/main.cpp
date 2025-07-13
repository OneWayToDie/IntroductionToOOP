#include<iostream>
using namespace std;

class String;
String operator+(String left, String right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int str1;
	int str2;
	int str3;
public:
	int get_str1()const
	{
		return str1;
	}
	int get_str2()const
	{
		return str2;
	}
	int get_str3()const
	{
		return str3;
	}
	void set_str1(int str1)
	{
		this->str1 = str1;
	}
	void set_str2(int str2)
	{
		this->str2 = str2;
	}
	void set_str3(int str3)
	{
		this->str3 = str3;
	}
	//					Constructors
	String()
	{
		/*this->str1 = 1;
		this->str2 = 0;	
		this->str3 = 0;
		cout << "DefaultConstructor:\t" << this << endl;*/
		set_str1(str1);
		this->str2 = 0;
		this->str3 = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(int str2)
	{
	/*	this->str1 = 0;
		this->str2 = 1;
		this->str3 = 0;
		cout << "SingleArgumentConstructor:\t" << this << endl;*/
		this->str1 = 0;
		set_str2(str2);
		this->str3 = 0;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	String(int str1, int str2, int str3)
	{
	/*	this->str1 = 1;
		this->str2 = 1;
		this->str3 = 0;
		cout << "Constructor:\t" << this << endl;*/
		this->str1 = 1;
		this->str2 = 1;
		set_str3(str3);
		cout << "Constructor:\t" << this << endl;
	}
	~String()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//					Operators
	
	//					Methods
	void print()
	{
		if (str1)
		{
			cout << "Hello ";
		}
		if (str2)
		{
			cout << "World";
		}
		if (str3)
		{
			cout << str3;
		}
		cout << endl;
	}
};
String operator+(String left, String right)
{
	return String
	(
		left.get_str1() + right.get_str2()
	);
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	/*os << obj.get_str3() << "Hello world";*/
	if (obj.get_str1())os << obj.get_str1();
	if (obj.get_str2())os << obj.get_str2();
	if (obj.get_str3())os << obj.get_str3();

	return os;
}

#define str_check
//#define ostream_check
void main()
{
	setlocale(LC_ALL, "");

#ifdef str_check
	String str1;
	str1.print();
	
	String str2 = 1;
	str2.print();

	String str3(1, 1, 0);
	str3.print();
#endif
#ifdef ostream_check
	String str3(1,1,0);
	cout << str3 << endl;
#endif
}