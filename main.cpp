#include <iostream>
#include"Matrix.h"

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Тест 1 создание" << std::endl;
	Matrix m1(2, 3);
	m1.fill(5);
	std::cout << "Тестовая матрица 2x3 с заполнением 5:\n";
	m1.print();
	return 0;
}

