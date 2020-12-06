#include <iostream>
#include <chrono>
#include "matrix.hpp"
using namespace std;
int main() {
	matrix a;
	matrix b;
	a.setcolum (5);
	a.setrow(5);
	b.setrow(5);
	b.setcolum(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j) {
				a.setnumber(i, j, 1);
				b.setnumber(i, j, 1);
			}
			else {
				a.setnumber(i, j, 0);
				b.setnumber(i, j, 0);
			}
		}
	}
	matrix c;
	c = b*3;
	matrix d = 2 * a;
	matrix e = c * d;
	cout << a.getrow() << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << e.getnumber(i,j) << " ";
		}
		cout << endl;
	}
}