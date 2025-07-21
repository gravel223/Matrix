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


    