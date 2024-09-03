#pragma once
#include <iostream>
#include <vector>
#include "Vector.h";
class Matrix {
protected:
	friend class Vector;
	std::vector<std::vector<float>> Matr;
	int size_row=0, size_col=0;
	friend void show(Matrix M);
public:
	Matrix();
	Matrix(int size_row, int size_col);

	Matrix(int size_row, int size_col, std::vector<float> vect);
	
	
	float operator()(int i, int j);
	

	void operator+(Matrix M2);

	void operator*(Matrix M2);

};


class MProj : public Matrix
{
public:
	MProj();

};


class MRotate : public Matrix {
public:
	MRotate(float alpha);
};


void show(Matrix M);
