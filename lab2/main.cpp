#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	Complex c1(1, 2);
	Complex c2(2, 3);

    Complex c3(0, 0);
    c3 = c1 + c2;

    cout << c1.Im << ' ' << c1.Re << endl;
    cout << c2.Im << ' ' << c2.Re << endl;
    cout << c3.Im << ' ' << c3.Re << endl;

	cout << (float) c3 << endl;


	Queue q(100);
	q << 1 << 2 << 3 << 5 << 6;
    cout << q.pop() << ' ';
    cout << q.pop() << ' ';
    cout << q.pop() << endl;

	return 0;
}
