#pragma once
#include <iostream>
#include "Matrix.h"
#include <string.h>
#include <cstdlib> 
#include <ctime>    
class Matrix
{
private:
	int rows;
	int cols;
	int** matrix;

	class Row { // прокси для столбцов
	private:
		int* data;
		int size;
	public:
		Row(int* data, int size) {
			this->data = data;
			this->size = size;
		}
		int& operator[](int j) {
			return data[j];
		}
	};

public:
	// конструкторы
	Matrix();                // конструктор по умолчанию
	Matrix(int rows, int cols);// конструктор с параметрами
	~Matrix();              // деструктор
	Matrix(const Matrix& other); // конструктор копирования
	Matrix& operator=(const Matrix& other); // оператор присваивания
	bool operator==(const Matrix& other) const; 
	bool operator!=(const Matrix& other) const;
	Matrix operator+(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix& operator++(); //  префиксный инкремент
	Matrix& operator--(); // префиксный декремент
	Matrix operator++(int); //  постфиксный инкремент
	Matrix operator--(int); //постфиксный декремент
	Row operator[](int col);
	void fill(int value); // заполнение
	void fillRand(); // заполнеие псевдослучайнаыми числами
	void print(); // вывод
	void setElement(int row, int col, int value); // получение элемента
	int getElement(int row, int col); // Получение элемента по индексу
	int getRows() const; // колличество строк
	int getCols() const;// колличество стобцов
	std::string toString() const; // Вывод матрицы в строку
};

