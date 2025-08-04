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
	// ������������
	Matrix();                // ����������� �� ���������
	Matrix(int rows, int cols);// ����������� � �����������
	~Matrix();              // ����������
	Matrix(const Matrix& other); // ����������� �����������
	Matrix& operator=(const Matrix& other); // �������� ������������
	bool operator==(const Matrix& other) const; 
	void fill(int value); // ����������
	void print(); // �����
	void setElement(int row, int col, int value); // ��������� ��������
	int getElement(int row, int col); // ��������� �������� �� �������
	int getRows() const; // ����������� �����
	int getCols() const;// ����������� �������
	std::string toString() const; // ����� ������� � ������
};

