#include "lib.h"
#include <math.h>

Complex::Complex(float _Re, float _Im) : Re(_Re), Im(_Im) {}

Complex Complex::operator+(const Complex &c)
{
	Complex res(this->Re + c.Re, this->Im + c.Im);
	return res;
}

Complex Complex::operator*(float f)
{
	Complex res(this->Re * f, this->Im * f);
	return res;
}

Complex Complex::operator*(const Complex &c)
{
	float a = this->Re;
	float b = this->Im;
	float x = c.Re;
	float y = c.Im;
	Complex res(a * x - b * y, a * y + b * x);
	return res;
}

Complex::operator float()
{
	return sqrt(Re * Re + Im * Im);
}

Queue::Queue(int n)
{
	Q = new int[n];
	b = 0;
	e = 0;
}

Queue::~Queue()
{
	delete [] Q;
}

int Queue::pop()
{
	return Q[b++];
}

Queue& Queue::operator<<(int x)
{
	Q[e++] = x;
	return *this;
}
