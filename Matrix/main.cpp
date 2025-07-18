#include<iostream>
using namespace std;

class Matrix;

class Matrix
{
	int size;
	int** matrix;
public:
	//					get_set Methods:
	int get_size()const
	{
		return size;
	}
	int** get_matrix()const
	{
		return matrix;
	}
	int** get_matrix()
	{
		return matrix;
	}
	//					Constructors
	explicit Matrix(int size = 3)
	{
		this->size = size;
		this->matrix = new int* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new int[size];
		}
		cout << "DefaultConstructor:\t" << this << endl;
	}

	~Matrix()
	{
		delete[] matrix;
		matrix = nullptr;
		size = 0;
		cout << "Destructor:\t\t" << this << endl;
	}

	//					Methods
	void blurring_numbers()	//FillRand, названный по-своему... захотел так... а что? КАКИЕ-ТО ПРОБЛЕМЫ?????
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = rand() % 100;
			}
		}
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++) 
			{
				cout << matrix[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

//Matrix operator+(const Matrix& left, const Matrix& right)
//{
//
//	
//}
//Matrix operator-(const Matrix& left, const Matrix& right)
//{
//
//
//}
//Matrix operator*(const Matrix& left, const Matrix& right)
//{
//
//
//}
//Matrix operator/(const Matrix& left, const Matrix& right)
//{
//
//
//}

void main()
{
	setlocale(LC_ALL, "");

	cout << "Первая матрица:" << endl;
	Matrix first_try;
	first_try.blurring_numbers();
	first_try.print();
	cout << "Вторая матрица:" << endl;
	Matrix second_try;
	second_try.blurring_numbers();
	second_try.print();
	//Matrix Plus = first_try + second_try;
	//Plus.print();
	//Matrix Plus = first_try - second_try;
	//Plus.print();
	//Matrix Plus = first_try * second_try;
	//Plus.print();
	//Matrix Plus = first_try / second_try;
	//Plus.print();
}