#pragma once
#include <functional>
#include "MyIterator.h"

using namespace std;

template<class T, class Compare = std::less<T>>
class BST
{
private:
    node<T> * root = nullptr;

	Compare comp = Compare();

	node<T> * find(node<T> * t, const T &k)
	{
		if (!t)
			return nullptr;
		if (comp(t->data, k))
            return find(t->right, k);
		else if (t->data != k)
			return find(t->left, k);

		return t;
	}

	size_t size(node<T> * t) const
	{
		if (t == nullptr)
			return 0;
		return 1 + size(t->left) + size(t->right);
	}

    void makeEmpty(node<T> * t)
    {
        if(t == nullptr)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node<T> * insert(const T &x, node<T>* t)
    {
        if(t == nullptr)
        {
            t = new node<T>();
            t->data = x;
            t->height = 0;
            t->left = t->right = nullptr;
            t->p = nullptr;
        }
        else if(Compare()(x, t->data))
        {
        	if (t->left)
				t->left->p = nullptr;
            t->left = insert(x, t->left);
            t->left->p = t;

            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x != t->data)
        {
        	if (t->right)
				t->right->p = nullptr;
            t->right = insert(x, t->right);
            t->right->p = t;

            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    node<T> * singleRightRotate(node<T> * &t)
    {
        node<T> * u = t->left;
        t->left = u->right;
        t->left->p = t;

        u->right = t;
        u->right->p = u;

        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;

        return u;
    }

    node<T> * singleLeftRotate(node<T> * &t)
    {
        node<T> * u = t->right;
        t->right = u->left;
        t->right->p = t;

        u->left = t;
        u->left->p = u;

        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    node<T> * doubleLeftRotate(node<T> * &t)
    {
        t->right = singleRightRotate(t->right);
        t->right->p = t;
        return singleLeftRotate(t);
    }

    node<T> * doubleRightRotate(node<T> * &t)
    {
        t->left = singleLeftRotate(t->left);
        t->left->p = t;
        return singleRightRotate(t);
    }

    node<T> * findMin(node<T> * t)
    {
        if(t == nullptr)
            return nullptr;
        else if(t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    node<T> * findMax(node<T> * t)
    {
        if(t == nullptr)
            return nullptr;
        else if(t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    node<T> * remove(const T &x, node<T> * t)
    {
        node<T> * temp;

        if(t == nullptr)
            return nullptr;

        else if(Compare()(x, t->data))
		{
            t->left = remove(x, t->left);
            t->left->p = t;
		}
        else if(x != t->data)
		{
            t->right = remove(x, t->right);
            t->right->p = t;
		}

        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
            t->right->p = t;
        }
        else
        {
            temp = t;
            if(t->left == nullptr)
                t = t->right;
            else if(t->right == nullptr)
                t = t->left;
            delete temp;
        }
        if(t == nullptr)
            return t;

        t->height = max(height(t->left), height(t->right))+1;

        if(height(t->left) - height(t->right) == 2)
        {
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            else
                return doubleLeftRotate(t);
        }
        else if(height(t->right) - height(t->left) == 2)
        {
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            else
                return doubleRightRotate(t);
        }
        return t;
    }

    size_t height(node<T> * t)
    {
        return (t == nullptr ? -1 : t->height);
    }

    size_t getBalance(node<T> * t)
    {
        if(t == nullptr)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void inorder(node<T> * t)
    {
        if(t == nullptr)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }



public:
	node<T> * getRoot()
	{
		return root;
	}

	typedef MyIterator<T> iterator;

	iterator begin()
	{
		if (!root)
			return iterator();

		node<T> * t = root;
		while(t->left)
			t = t->left;

		return iterator(t);
	}

	iterator end()
	{
		return iterator();
		/*if (!root)
			return iterator();

		node<T> * t = root;
		while(t->right)
			t = t->right;

		return iterator(t);*/
	}


	BST() {};

	BST(const BST & t){}

	BST& operator=(const BST &);

	template<class InputIt>
	void assign(InputIt first, InputIt last);

	iterator insert(const T &value)
	{
		root = insert(value, root);
		return iterator(root);
	}

	iterator remove(const T &value)
	{
		root = remove(value, root);
		return iterator(root);
	}

	iterator find(const T &value)
	{
		return iterator(find(root, value));
	}

	bool empty() const
	{
        if (root)
			return false;
		return true;
	}

	size_t size() const
	{
		return size(root);
	}


	friend class MyIterator<T>;
};
