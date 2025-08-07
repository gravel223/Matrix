
#include "Matrix.h"
#include <iostream>
#include<string>

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

    bool Matrix::operator!=(const Matrix& other) const {
        if (this->cols != other.cols || this->rows != other.rows) {
            return true;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != other.matrix[i][j]) {
                    return true;
                }
            }
        }
        return false;
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
    void Matrix::setElement(int row, int col, int value) {
        if (matrix == nullptr || row < 0 || row >= rows || cols < 0 || col >= cols) {
            std::cout << "Ошибка: некорректные значения!" << std::endl;
            return;
        }
        matrix[row][col] = value;
    }

    int Matrix::getElement(int row, int col) {
        if (matrix == nullptr) {
            std::cout << "Ошибка: матрица пуста!" << std::endl;
            return 0;
        }
        if (row < 0 || row >= rows || cols < 0 || col >= cols) {
            std::cout << "Ошибка: некорректные значения!" << std::endl;
            return 0;
        }
        return matrix[row][col];
    }

    int Matrix::getRows() const {
        if (matrix == nullptr) {
            std::cout << "Ошибка: матрица не инициализирована!" << std::endl;
            return 0;
        }
        return rows;
    }

    int Matrix::getCols() const {
        if (matrix == nullptr) {
            std::cout << "Ошибка: матрица не инициализирована!" << std::endl;
            return 0;
        }
        return cols;
    }

    std::string Matrix::toString() const {
        if (matrix == nullptr) {
            return "Матрица не инициализирована";
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

    Matrix Matrix::operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cout << "поля матрицы должны быть равны!" << std::endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }



    