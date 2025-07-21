#pragma once
class Matrix
{
private:
	int rows;
	int cols;
	int** matrix;
public:
	// конструкторы
	Matrix();                // конструктор по умолчанию
	Matrix(int rows, int cols);// конструктор с параметрами
	~Matrix();              // деструктор
	Matrix(const Matrix& other); // конструктор копирования
	Matrix& operator=(const Matrix& other); // оператор присваивания
	void fill(int value); // заполнение
	void print(); // вывод
	void setElement(int row, int col, int value); // получение элемента
	int getElement(int row, int col); // Получение элемента по индексу
};

