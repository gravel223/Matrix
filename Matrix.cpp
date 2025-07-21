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

    //���������� ������������ �����������
    Matrix::Matrix(const Matrix& other) {
        // ������� ���������, ��� �������� ������ �������
        if (other.matrix == nullptr) {
            // � ���� ������ ������� ������ �������
            rows = 0;
            cols = 0;
            matrix = nullptr;
            return; // ��������� ���������� ������������
        }

        rows = other.rows;
        cols = other.cols;

        matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    // ���������� ��������� ������������
    Matrix& Matrix::operator=(const Matrix& other)
    {
        if (this == &other) {
            return *this;
        }
        if (matrix != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }
        rows = other.rows;
        cols = other.cols;

        matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        return *this;
    }

    void Matrix::fill(int value) {
        if (matrix == nullptr) {
            std::cout << "������� �����!" << std::endl;
            return;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = value;
            }
        }
    }

    void Matrix::print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    
    


    