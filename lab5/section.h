#pragma once
#include "interfaces.h"

class Section : public Object
{
private:
	CVector2D beg;
	CVector2D end;


public:
	Section() {}
	Section(const CVector2D &_beg, const CVector2D &_end) : beg(_beg), end(_end) {}
	Section(double x1, double y1, double x2, double y2)
	{
		beg.x = x1;
		beg.y = y1;
		end.x = x2;
		end.y = y2;
	}

	//IGeoFig
    double square() const
    {
    	return 0;
    }

    double perimeter() const
    {
    	return (end-beg).length();
    }


	//IPhysObject
    double mass() const
    {
    	return 0;
    }

	CVector2D position()
	{
		return CVector2D((beg.x+end.x)/2.0, (beg.y+end.y)/2.0);
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
		cout << "\tBegin: "; beg.draw();
		cout << "\tEnd: "; end.draw();
		cout << "\tPerimeter: " << perimeter() << '\n';
		cout << "\tSquare: " << square() << '\n';
		cout << "\tMass: " << mass() << '\n';
		cout << "\tMassPos: "; position().draw();
		cout << "\tSize: " << size() << "\n}\n\n";
	}


	//IDialogInitiable
	void initFromDialog()
	{
		cout << "Init Segment from keyboard:\n";
        cout << "Begin vector: ";
        beg.initFromDialog();
        cout << "End vector: ";
        end.initFromDialog();
	}

    const char* classname()
    {
    	return "Segment";
    }

    unsigned int size()
    {
		return sizeof(*this);
    }
};
