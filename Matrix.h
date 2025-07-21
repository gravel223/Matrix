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
};

