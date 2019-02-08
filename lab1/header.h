#ifndef HEADER_H
#define HEADER_H


struct comp;
//{
//	float re;
//	float im;
//}

struct matrix;
//{
//    float mat[3][3];
//}

void add(float &a, float b); //2
void add(float *a, float b); //2


void changesign(float &a); //7
void changesign(float *a); //7


void conjugate(comp &z); //10
void conjugate(comp *z); //10


void mul(matrix &m, float f); //15
void mul(matrix *m, float f); //15

#endif // HEADER_H
