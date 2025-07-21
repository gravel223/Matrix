#include "Matrix.h"
#include <iostream>

// реализация конструктора по умолчанию
Matrix::Matrix() {
	this->rows = 0;
	this->cols = 0;
	matrix = nullptr;
}
// реализация конструктора с параметрами
Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    // выделяем память
    matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    // заполняем нулями
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
}
    //реализация деструктора
    Matrix::~Matrix() {
        if (matrix != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }

    }

    //реализация конструктора копирования
    Matrix::Matrix(const Matrix& other) {
        // Сначала проверяем, что исходный объект валиден
        if (other.matrix == nullptr) {
            // В этом случае создаем пустую матрицу
            rows = 0;
            cols = 0;
            matrix = nullptr;
            return; // завершаем выполнение конструктора
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
    // реализация оператора присваивания
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
            std::cout << "Матрица пуста!" << std::endl;
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
    
    


    