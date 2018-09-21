#include <iostream>
using namespace std;
int main() {
	int rowsize, colsize,j, previousrow, previouscol;
	int i = 0;
	cout << "enter odd size of matrix " << endl;
	cin >> rowsize;
	colsize = rowsize;
	int**magicsquare = new int *[rowsize];
	for (int i = 0; i < rowsize; i++) {
		*(magicsquare + i) = new int[colsize];
	}
	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < colsize; j++) {
			*(*(magicsquare + i) + j) = 0;
		}
	}
	j = rowsize / 2;
	for (int number = 1; number <= rowsize*rowsize; number++) {
		*(*(magicsquare + i) + j) = number;
		previousrow = i;
		previouscol = j;
		if (i == 0 && j != rowsize - 1) {
			i = rowsize - 1;
			j++;
		}
		else if (i == 0 && j == rowsize - 1) {
			i = rowsize - 1;
			j = 0;
		}
		else if (i != 0 && j != rowsize - 1) {
			i--;
			j++;
		}
		else if (j == rowsize - 1 && i != 0) {
			j = 0;
			i--;
		}
		if (*(*(magicsquare + i) + j) != 0) {
			i = ++previousrow;
			j = previouscol;
		}
	}
	cout << "magic square is " << endl;
	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < rowsize; j++) {
			cout << *(*(magicsquare + i) + j) << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < rowsize; i++) {
		delete[] * (magicsquare + i);
	}
	delete[]magicsquare;
	system("pause");
	return 0;
}