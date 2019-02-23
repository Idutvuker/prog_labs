#ifndef LIB_H
#define LIB_H

class Complex
{
public:
	float Re;
	float Im;

	Complex(float _Re, float _Im);

	Complex operator*(float f);
	Complex operator*(const Complex &c);
	Complex operator+(const Complex &c);
	operator float();
};

class Queue
{
public:
    int * Q;
    int b;
    int e;

    Queue(int n);
    ~Queue();

    Queue& operator<<(int x);
    int pop();
};


#endif // LIB_H
