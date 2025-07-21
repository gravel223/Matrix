#include "Matrix.h"
#include <iostream>

// ���������� ������������ �� ���������
Matrix::Matrix() {
	this->rows = 0;
	this->cols = 0;
	matrix = nullptr;
}
// ���������� ������������ � �����������
Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    // �������� ������
    matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    // ��������� ������
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
}
    //���������� �����������
    Matrix::~Matrix() {
        if (matrix != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }

    }


    