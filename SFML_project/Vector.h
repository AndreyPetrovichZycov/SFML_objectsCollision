#pragma once
#include <iostream>
#include <vector>
#include "Matrix.h";
#include <cmath>

class Vector {
protected:
	std::vector<float> vect;
	friend class Matrix;
	friend void Show(Vector v);
public:
	Vector();
	
	Vector(int size);

	Vector(std::vector<float> vect);


	Vector operator+(Vector v);


	float operator*(Vector v);


	Vector operator*(float a);


	Vector operator*(Matrix M);


	void operator=(Vector v1);


	float X();


	float Y();


	float norma();


	bool operator==(Vector v);


	bool operator==(std::vector<float> v);

};


void Show(Vector v);