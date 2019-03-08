#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
    Set s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(0);
    s1.insert(4);

    Set s2;
    s2.insert(1);
    s2.insert(5);
    s2.insert(0);
    s2.insert(3);
    s2.erase(1);

	cout << s1.contains(10) << endl;
	cout << s1.contains(0) << endl;

    s1.intersect(s2).print();
    s1.sunion(s2).print();

	return 0;
}
