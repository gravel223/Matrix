#pragma once
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
};

