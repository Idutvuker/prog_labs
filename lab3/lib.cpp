#include <set>

#include "lib.h"

bool Set::contains(int x)
{
    return (this->find(x) != this->end());
}

Set Set::intersect(const Set &s)
{
	Set res;
	std::set_intersection(this->begin(), this->end(), s.begin(), s.end(),
							std::inserter(res, res.begin()));
	return res;
}

Set Set::sunion(const Set &s)
{
	Set res;
	std::set_union(this->begin(), this->end(), s.begin(), s.end(),
							std::inserter(res, res.begin()));
	return res;
}

void Set::print()
{
	std::cout << "{ ";
    for (int x : *this)
		std::cout << x << ' ';
	std::cout << '}' << std::endl;
}
