#pragma once
#include <math.h>

using namespace std;

class Trapezoid : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject
{
private:
	double height;
	double base1;
	double base2;

public:
	Trapezoid() {}
	Trapezoid(double _height, double _base1, double _base2) : height(_height), base1(_base1), base2(_base2) {}

	//IGeoFig
    double square() const
    {
    	return (base1 + base2) / 2 * height;
    }

    double perimeter() const
    {
    	double x = fabs(base1 - base2) / 2.0;
    	double side = (x * x + height * height);

    	return side * 2 + base1 + base2;
    }


	//IPhysObject
    double mass() const
    {
    	return square();
    }

	CVector2D position()
	{
		return CVector2D(0, 0);
	}

	bool operator==(const IPhysObject &ob) const
	{
		if (mass() == ob.mass())
			return true;
		return false;
	}

	bool operator<(const IPhysObject &ob) const
	{
		if (mass() < ob.mass())
			return true;
		return false;
	}


	//IPrintable
	void draw()
	{
		cout << classname() << " {\n";
		cout << "\tBase1: " << base1 << '\n';
		cout << "\tBase2: " << base2 << '\n';
		cout << "\tHeight: " << height << '\n';
		cout << "\tPerimeter: " << perimeter() << '\n';
		cout << "\tSquare: " << square() << '\n';
		cout << "\tMass: " << mass() << '\n';
		cout << "\tMassPos: "; position().draw();
		cout << "\tSize: " << size() << "\n}\n\n";
	}


	//IDialogInitiable
	void initFromDialog()
	{
		cout << "Init Trapezoid from keyboard:\n";
        cout << "Base1: ";
        cin >> base1;
        cout << "Base2: ";
        cin >> base2;
        cout << "Height: ";
        cin >> height;
	}

    const char* classname()
    {
    	return "Trapezoid";
    }

    unsigned int size()
    {
		return sizeof(*this);
    }
};
