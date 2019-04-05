#include <iostream>
#include "section.h"
#include "trapezoid.h"
#include <vector>

using namespace std;


vector <Object*> vect;

int main()
{
	Trapezoid t;
	t.initFromDialog();
	vect.push_back(&t);

	vect[0]->draw();

	return 0;
}
