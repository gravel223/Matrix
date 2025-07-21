#include <iostream>
#include"Matrix.h"
#include <string.h>

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Тест 1 создание" << std::endl;
	Matrix m1(2, 3);
	m1.fill(5);
	std::cout << "Тестовая матрица 2x3 с заполнением 5:\n";
	m1.print();
    std::cout << "Тест 2: копирование" << std::endl;
    Matrix m2 = m1;
    std::cout << "\nКопия матрицы:\n";
    m2.print();

    std::cout << "Тест 3: проверка пустой матрицы" << std::endl;
    Matrix empty;
    std::cout << "\nПроверка пустой матрицы:\n";
    empty.print();

    std::cout << "Тест 4: создание маленькой матрицы" << std::endl;
    Matrix small(1, 1);
    small.fill(10);
    std::cout << "\nМатрица 1x1:\n";
    small.print();

    Matrix m(2, 2);
    m.fill(4);
    m.print();

    m.setElement(0, 0, 5);  // должно сработать
    m.setElement(1, 1, 10); // должно сработать
    m.setElement(2, 2, 15); // должно вызвать ошибку

    std::cout << "Вывод зеначений:" << std::endl;
    std::cout << m.getElement(0, 0) << std::endl;  // должно сработать
    std::cout << m.getElement(1, 1) << std::endl; // должно сработать
    std::cout << m.getElement(2, 2) << std::endl; // должно вызвать ошибку

    std::cout << "вывод в строку" << std::endl;
    std::cout << m1.toString() << std::endl; // вывод в строку

    return 0;
	
}

