#pragma once

#include "BTS.h"


template<class T>
struct node
    {
        T data;
        node* left;
        node* right;
        size_t height;
        node* p;
    };


template <class T>
class MyIterator
{
private:
    node<T> * n = nullptr;

public:
	MyIterator(){}
	MyIterator(node<T> * x) : n(x) {}
	MyIterator(const MyIterator& mit) : n(mit.n) {}

	MyIterator& operator++()
	{
		node<T> * t = n->right;
        if (t)
        {
			while(t->left) t = t->left;
        }
		else
		{
			node<T> * prev = n;
			t = n->p;
            while(t)
            {
            	if (t->left == prev)
					break;

				prev = t;
            	t = t->p;
            }
		}

		n = t;

		return *this;
	}


	bool operator==(const MyIterator& rhs) const {return n==rhs.n;}
	bool operator!=(const MyIterator& rhs) const {return n!=rhs.n;}
	T& operator*() {return n->data;}
};
