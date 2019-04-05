#include <iostream>

using namespace std;

template <class T>
swp (T &a, T &b)
{
	T tmp = b;
	b = a;
	a = tmp;
}

template <int N, class T>
class Array
{
public:
    T raw[N];
};

int main()
{
	/*pair <int, int> p1 = {0, 0};
	pair <int, int> p2 = {1, 1};

	swp < pair <int, int> > (p1, p2);

    cout << p1.first <<' '<<p1.second << endl << p2.first <<' '<<p2.second << endl << endl;*/

    Array <10, float> arr;
	arr.raw[3] = 1.01f;
	cout << arr.raw[3] << endl;

    return 0;
}
