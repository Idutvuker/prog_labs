#include <bits/stdc++.h>

using namespace std;

struct Point{
	int x,y;
	Point(int _x, int _y) : x(_x), y(_y) {}
};

bool pred_int(int t)
{
	return (t > 3);
}

bool pred_point(const Point &t)
{
	return (t.x > 3);
}

template <class T, class P>
bool my_all_of(T a, T b, P f)
{
	for (auto & x = a; x != b; x++)
        if (!f(*x))
			return false;

	return true;
}

template <class T, class P>
bool my_is_partitioned(T a, T b, P f)
{
	bool flag = f(*a);
	bool changed = false;
	for (auto &x = a; x != b; x++)
		if (flag != f(*x))
		{
			if (changed)
				return false;
			else
			{
				changed = true;
				flag = !flag;
			}
		}

	return true;
}

template <class T, class P>
T my_find_backward(T a, T b, P t)
{
	b--;
	a--;
	for (auto &x = b; x != a; x--)
	{
        if (*x == t)
			return x;
	}
	return (++b);
}

int main()
{
	vector<int> v1 = {6, 5, 8, 3, 2, 1};
	vector<Point> v2;
    v2.push_back(Point(5, 10));
    v2.push_back(Point(6, 10));

	cout << my_all_of(v1.begin(), v1.end(), pred_int) << endl;
	cout << my_all_of(v2.begin(), v2.end(), pred_point) << endl;

	cout << my_is_partitioned(v1.begin(), v1.end(), pred_int) << endl;

	cout << *my_find_backward(v1.begin(), v1.end(), 8) << endl;

    return 0;
}
