#ifndef LIB_H
#define LIB_H

#include <set>
#include <algorithm>
#include <iostream>


class Set : public std::set <int>
{
public:
    bool contains(int x);
	Set intersect(const Set &s);
	Set sunion(const Set &s);
	void print();
};


#endif // LIB_H
