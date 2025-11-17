#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Matrix
{
	T** mas;
	int n;
	int m;
	static int kol;
public:
	Matrix(int, int);
	Matrix();
	Matrix(const Matrix&);
	Matrix<T>& operator=(const Matrix&);
	Matrix<T> operator+(const Matrix&);
	Matrix<T> operator-(const Matrix&);
	void Rand();
	void Print();
	void inMatrix();
	void max_min_Matrix();
	~Matrix();
};

template<typename T>
int Matrix<T>::kol = 0;

template<typename T>
inline Matrix<T>::Matrix(int pn, int pm) :n{ pn }, m{ pm }
{
	mas = new T * [n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new T[m];
	}
	kol++;
}

template<typename T>
inline Matrix<T>::Matrix() :mas{ nullptr }, n{ 0 }, m{ 0 } 
{
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix& copy)
{
	n = copy.n;
	m = copy.m;
	mas = new T * [n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new T[m];
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = copy.mas[i][j];
		}
	}
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix& copy)
{
	if (this != &copy)
	{
		if (mas != nullptr)
		{
			this->~Matrix();
		}
		n = copy.n;
		m = copy.m;
		mas = new T * [n];
		for (int i = 0; i < n; i++)
		{
			mas[i] = new T[m];
			for (int j = 0; j < m; j++)
			{
				mas[i][j] = copy.mas[i][j];
			}
		}
	}
	return *this;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(const Matrix& obj)
{
	Matrix<T> rez(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			rez.mas[i][j] = mas[i][j] + obj.mas[i][j];
		}
	}
	return rez;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator-(const Matrix& obj)
{
	Matrix<T> rez(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			rez.mas[i][j] = mas[i][j] - obj.mas[i][j];
		}
	}
	return rez;
}

template<typename T>
inline void Matrix<T>::Rand()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = rand() % 21;
		}
	}
}

template<typename T>
inline void Matrix<T>::Print()
{ 
	cout << "Matrix " << kol << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

template<typename T>
inline void Matrix<T>::inMatrix()
{
	cout << "Enter elements of the matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mas[i][j];
		}
	}
}

template<typename T>
inline void Matrix<T>::max_min_Matrix()
{
	auto max = mas[0][0];
	auto min = mas[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(max<mas[i][j])
				max = mas[i][j];
			if (min > mas[i][j])
				min = mas[i][j];
		}
	}
	cout << "Max=" << max << "\n";
	cout << "Min=" << min << "\n";
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;
	kol--;
}