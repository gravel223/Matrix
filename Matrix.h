#pragma once
#include <iostream>
#include "Matrix.h"
#include <string.h>
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
	bool operator==(const Matrix& other) const; 
	void fill(int value); // заполнение
	void print(); // вывод
	void setElement(int row, int col, int value); // получение элемента
	int getElement(int row, int col); // Получение элемента по индексу
	int getRows() const; // колличество строк
	int getCols() const;// колличество стобцов
	std::string toString() const; // Вывод матрицы в строку
};

