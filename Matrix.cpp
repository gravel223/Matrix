#include "Matrix.h"
#include <iostream>
#include<string>

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

    bool Matrix::operator==(const Matrix& other) const {
        if (this->cols != other.cols || this->rows != other.rows) {
            return false;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != other.matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
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
    void Matrix::setElement(int row, int col, int value) {
        if (matrix == nullptr || row < 0 || row >= rows || cols < 0 || col >= cols) {
            std::cout << "������: ������������ ��������!" << std::endl;
            return;
        }
        matrix[row][col] = value;
    }

    int Matrix::getElement(int row, int col) {
        if (matrix == nullptr) {
            std::cout << "������: ������� �����!" << std::endl;
            return 0;
        }
        if (row < 0 || row >= rows || cols < 0 || col >= cols) {
            std::cout << "������: ������������ ��������!" << std::endl;
            return 0;
        }
        return matrix[row][col];
    }

    int Matrix::getRows() const {
        if (matrix == nullptr) {
            std::cout << "������: ������� �� ����������������!" << std::endl;
            return 0;
        }
        return rows;
    }

    int Matrix::getCols() const {
        if (matrix == nullptr) {
            std::cout << "������: ������� �� ����������������!" << std::endl;
            return 0;
        }
        return cols;
    }

    std::string Matrix::toString() const {
        if (matrix == nullptr) {
            return "������� �� ����������������";
        }

        std::string st = "";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                st += std::to_string(matrix[i][j]) + " ";
            }
            st += "\n";
        }
        return st;
    }

    
    


    