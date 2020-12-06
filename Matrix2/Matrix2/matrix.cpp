#include <iostream>
#include <immintrin.h>
#include <omp.h>
#include "matrix.hpp"
void matrix::setrow(int row) {
	this->row = row;
}
void matrix::setcolum(int colum) {
	this->colum = colum;
}
void matrix:: setmatrix(float(*matrix1)[200]) {
	this->matrix1 = matrix1;
}
int matrix::getrow() {
	return row;
}
int matrix::getcolum() {
	return colum;
}
float matrix::getnumber(int row, int colum) {
	return matrix1[row][colum];
}
void matrix::setnumber(int row, int colum, float number) {
	this->matrix1[row][colum] = number;
}
matrix operator*(matrix& a, float b)
{
	matrix c;
	c.setcolum(a.getcolum());
	c.setrow(a.getrow());
	for (int i = 0; i < a.getrow(); i++) {
		for (int j = 0; j < a.getcolum();j++) {
			float number = a.getnumber(i, j) * b;
			c.setnumber(i, j, number);
		}
	}
		return c;
}

matrix operator*(float b, matrix& a)
{
	matrix c;
	c.setcolum(a.getcolum());
	c.setrow(a.getrow());
	for (int i = 0; i < a.getrow(); i++) {
		for (int j = 0; j < a.getcolum(); j++) {
			float number = a.getnumber(i,j) * b;
			c.setnumber(i,j,number);
		}
	}
	return c;
}
matrix operator*(const matrix& a,const matrix& b) {
	matrix c;
	c.setcolum(a.colum);
	c.setrow(b.row);
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < b.colum; j++) {
			float number = 0.0f;
			for (int k = 0; k < a.colum; k++) {
				number += a.matrix1[i][k] * b.matrix1[k][j];
			}
			c.setnumber(i, j, number);
		}
	}
	return c;
}
ostream& operator<<(ostream& os, const matrix& a)
{
	os << a.colum;
	os << a.row;
	os << a.matrix1;
	return os;
}
matrix matrix::operator=(const matrix& a) {
	if (this == &a) {
		return *this;
	}
	delete[] matrix1;
	row = a.row;
	colum = a.colum;
	matrix1 = a.matrix1;
	return *this;
}
matrix::matrix(const matrix& obj) {
	this->colum = obj.colum;
	this->row = obj.row;
	this->matrix1 = obj.matrix1;
}

