#pragma once
#include <math.h>

using namespace std;

class CVector2D;

class IGeoFig
{
public:
	virtual double square() const = 0;
	virtual double perimeter() const = 0;
};



class IPhysObject
{
public:
	virtual double mass() const = 0;

	virtual CVector2D position() = 0;

	virtual bool operator== ( const IPhysObject& ob ) const = 0;

	virtual bool operator< ( const IPhysObject& ob ) const = 0;
};


class IPrintable
{
public:
	virtual void draw() = 0;
};


class IDialogInitiable
{
public:
	virtual void initFromDialog() = 0;
};

class BaseCObject
{
public:
	virtual const char* classname() = 0;
	virtual unsigned int size() = 0;
};

class CVector2D : public IDialogInitiable, public IPrintable
{
	public:
	double x, y;

	CVector2D(double _x, double _y) : x(_x), y(_y) {}

	double length()
	{
		return sqrt(x*x + y*y);
	}

	CVector2D() : x(0), y(0) {}

	CVector2D operator-(const CVector2D &v) const
	{
		CVector2D res(x - v.x, y - v.y);
		return res;
	}

	void draw()
	{
		cout << '{' << x << ", " << y << "}\n";
	}

    void initFromDialog()
    {
    	cin >> x >> y;
    }
};


class Object : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject
{};
