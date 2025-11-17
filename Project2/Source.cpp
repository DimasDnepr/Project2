/*Завдання
Створіть шаблонний клас матриця. Необхідно реалізувати динамічне виділення пам'яті, 
	очищення пам'яті, заповнення матриці з клавіатури, заповнення випадковими значеннями, 
	відображення матриці, арифметичні операції за допомогою перевантажених операторів (+, -), 
	пошук максимального і мінімального елемента.*/


#include<iostream>
#include"Matrix.h"
using namespace std;
int main()
{
	Matrix<int> obj(3, 4);
	obj.Rand();
	obj.Print();
	Matrix<int> obj1(3, 4);
	obj1.Rand();
	obj1.Print();
	Matrix<int> obj2 = obj + obj1;
	obj2.Print();
	Matrix<int> obj3 = obj - obj1;
	obj3.Print();
	Matrix<int>obj4(3,4);
	obj4.inMatrix();
	obj4.Print();
	obj.max_min_Matrix();
}
