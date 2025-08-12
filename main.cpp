#include <iostream>
#include"Matrix.h"
#include <string.h>
#include <windows.h>

int main()
{
    // Устанавливаем кодировку консоли
    SetConsoleCP(65001);     // для ввода
    SetConsoleOutputCP(65001); // для вывода
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

    Matrix a(2, 2);
    Matrix b(2, 2);

    a.setElement(0, 0, 1);
    b.setElement(0, 0, 1);

    if (a == b) {
        std::cout << "Матрицы равны" << std::endl;

    }

    std::cout << "умножение матриц" << std::endl;
   Matrix m3(2, 2);
   Matrix m4(2, 2);
   Matrix m5(2, 2);
   m3.fill(2);
   m4.fill(3);
   m5 = m3 * m4;
   m5.print();
   std::cout << "умножение матриц ошибка" << std::endl;
   Matrix m6(3, 3);
   m6 = m3 * m4;
   m6.print();

    std::cout << "префиксный инкремент" << std::endl;
    Matrix m7(3, 4);
    m7.fill(2);
    m7.print();
    ++m7;
    std::cout << std::endl;
    m7.print();
    return 0;
}