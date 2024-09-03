#include "Matrix.h"

Matrix::Matrix(){}

Matrix::Matrix(int size_row, int size_col) {
	this->size_col = size_col;
	this->size_row = size_row;
	Matr.resize(size_col, std::vector<float>(size_row));
}

Matrix::Matrix(int size_row, int size_col, std::vector<float> vect) {
	this->size_col = size_col;
	this->size_row = size_row;
	Matr.resize(size_col, std::vector<float>(size_row));
	for (int i = 0; i < size_row; i++) {
		for (int j = 0; j < size_col; j++) {
			Matr[i][j] = vect[i * size_row + j];
		}
	}
}

float Matrix::operator()(int i, int j) {
	return Matr[i][j];
}


void Matrix::operator+(Matrix M2) {
	if (M2.Matr.size() == Matr.size() && M2.Matr[0].size() == Matr[0].size()) {
		for (int i = 0; i < Matr.size(); i++) {
			for (int j = 0; j < Matr[0].size(); j++) {
				Matr[i][j] += M2.Matr[i][j];
			}
		}
	}
	else {
		std::cout << "not same size!" << std::endl;
		return;
	}
}


void Matrix::operator*(Matrix M2) {
	if (Matr.size() == M2.Matr[0].size() && Matr[0].size() == M2.Matr.size())
	{
		float s = 0;
		for (int i = 0; i < Matr.size(); i++)
		{
			for (int j = 0; j < Matr[0].size(); j++) {
				for (int k = 0; k < Matr.size(); k++) {
					s += Matr[i][k] * M2.Matr[k][j];
				}
			}
		}
	}

}

//наследуем матрицу проекции


MProj::MProj() : Matrix(2, 2) {
	Matr[0][0] = 1;
	Matr[1][0] = 0;
	Matr[0][1] = 0;
	Matr[1][1] = 0;
}


//матрица поворота
MRotate::MRotate(float alpha) : Matrix(2, 2) {
	Matr[0][0] = cos(alpha);
	Matr[1][0] = sin(alpha);
	Matr[0][1] = -sin(alpha);
	Matr[1][1] = cos(alpha);
}






void show(Matrix M) {
	for (int i = 0; i < M.size_row; i++) {
		for (int j = 0; j < M.size_col; j++) {
			std::cout << M.Matr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}