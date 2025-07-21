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
	Matrix(const Matrix& other); // ����������� �����������
	Matrix& operator=(const Matrix& other); // �������� ������������
	void fill(int value); // ����������
	void print(); // �����
	void setElement(int row, int col, int value); // ��������� ��������
	int getElement(int row, int col); // ��������� �������� �� �������
};

