#include <iostream>
#include"Matrix.h"
#include <string.h>
#include <windows.h>
#include <cstdlib> 
#include <ctime>   

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
   Matrix m7(3, 3);
   Matrix m6 = m3 * m7;
   m6.print();

    std::cout << "префиксный инкремент" << std::endl;
    Matrix m8(3, 4);
    m8.fill(2);
    m8.print();
    ++m8;
    std::cout << std::endl;
    m8.print();

    std::cout << "префиксный декремент" << std::endl;
    --m8;
    std::cout << std::endl;
    m8.print();

    std::cout << "\n=== Тест: Постфиксный инкремент (matrix++) ===\n";

    // Создаём матрицу 2x2 и заполняем значениями
    Matrix m9(2, 2);
    m9.setElement(0, 0, 1);
    m9.setElement(0, 1, 2);
    m9.setElement(1, 0, 3);
    m9.setElement(1, 1, 4);

    std::cout << "Оригинальная матрица m:\n";
    m9.print();

    // Применяем постфиксный инкремент: сначала копируется старое значение, потом m увеличивается
    Matrix m9_copy = m9++;
    std::cout << "\nРезультат m++ (копия до инкремента):\n";
    m9_copy.print(); // Должно быть: 1 2; 3 4

    std::cout << "\nТекущая матрица m (после инкремента):\n";
    m9.print(); // Должно быть: 2 3; 4 5

    std::cout << "\n=== Тест: Постфиксный декремент (matrix--) ===\n";
    std::cout << "Оригинальная матрица m:\n";
    m9.print();
    m9_copy = m9--;
    std::cout << "\nРезультат m++ (копия до декремента):\n";
    m9_copy.print();
    std::cout << "\nТекущая матрица m (после декремента):\n";
    m9.print();
    std::cout << "матрица случайных чисел" << std::endl;
    Matrix m10(3, 3);
    m10.fillRand();
    m10.print();
    std::cout << "перезагрузка оператора индексирования" << std::endl;
    std::cout << "m10[1][1] = 69" << std::endl;
    std::cout << m10[1][1] << std::endl; 
    std::cout << "m10[0][2] = 34" << std::endl;
    std::cout << m10[0][2] << std::endl; 

    
    return 0;
}