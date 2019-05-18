#include <iostream>
#include "header.h"

using namespace std;

struct comp
{
	float re;
	float im;
	comp(float _re, float _im): re(_re), im(_im) {}
};

struct matrix
{
    float mat[3][3];
    void print()
    {
    	for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << mat[i][j] << '\t';
			cout << endl;
		}
		cout << endl;
    }
};

void add(float &a, float b) // 2
{
	a += b;
}
void add(float *a, float b) // 2
{
	*a += b;
}


void changesign(float &a) //7
{
	a *= -1;
}
void changesign(float *a) //7
{
	*a *= -1;
}


void conj(comp &z) //10
{
    z.im *= -1;
}
void conj(comp *z) //10
{
	z->im *= -1;
}


void mul(matrix &m, float f) //15
{
    for (int i = 0; i < 9; i++)
		m.mat[i/3][i%3] *= f;
}
void mul(matrix *m, float f) //15
{
	for (int i = 0; i < 9; i++)
		m->mat[i/3][i%3] *= f;
}



int main()
{
	/*float a = 5;
	cout << a << ' ';
    add(a, 4);
    cout << a << ' ';
	add(&a, 1);
	cout << a << endl << endl;

	changesign(a);
	cout << a << endl;
	changesign(&a);
	cout << a << endl << endl;


    comp c(5.3f, -1.2f);
    conj(c);
    cout << c.re << ' ' << c.im << endl;
    conj(&c);
	cout << c.re << ' ' << c.im << endl << endl;

	int A[9] = {-1, -2, 3, 4, 5, 0, 6, 7, 8};

	matrix m;
	for (int i = 0; i < 9; i++)
		m.mat[i/3][i%3] = A[i];

    m.print();

    mul(m, -1);
    m.print();

    mul(&m, 2);
    m.print();*/


	return 0;
}
