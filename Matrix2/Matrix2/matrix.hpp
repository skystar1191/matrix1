#pragma once
#include <cstddef>
#include <iostream>
using namespace std;
class matrix {
private :
	int row = 0;
	int colum = 0;
	float(*matrix1)[200] = new float[200][200];
public:
	void setrow(int row);
	void setcolum(int colum);
	void setmatrix(float(*matrix1)[200]);
	int getrow();
	int getcolum();
	float getnumber(int row,int colum);
	void setnumber(int row, int colum,float number);
friend matrix operator*(matrix& a, float b);
friend matrix operator*(float b, matrix& a);
friend matrix operator*(const matrix& a,const matrix &b);
matrix operator=(const matrix& a);
friend ostream& operator<<(ostream& os, const matrix& st);
friend istream& operator>>(istream& is, matrix& st);
matrix(const matrix& obj);//copty constructor
matrix() {}//default constructor
matrix(int row, int colum) {
	this->colum = colum;
	this->row = row;
	float(*matrix1)[200] = new float[200][200];
}
};
