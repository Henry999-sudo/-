#include <iostream>
#ifndef ROBOCUB_SECOND_HOMEWORK
using namespace std;
class point
{
private:
    int x;
    int y;
public:
    point(int xValue, int yValue);
    ~point();
    point & operator = (const point &p); 
    inline void print(){
    	cout << "(" << x << "," << y << ")";
	}
};

point::point(int xValue, int yValue):x(xValue),y(yValue)
{
};

point::~point()
{
};

point & point::operator = (const point &p)
{
    x = p.x;
    y = p.y;
    return *this;
}

class line
{
private:
    int A;
    int B;
    int C;

public:
    line(int AValue, int BValue, int CValue);
    ~line();
    friend int Intersection(const line & FirstLine, const line & SecondLine, point &t);
};

/**
 * return : -1��������������,1����û�н��㣬0����һ������ 
 */
int Intersection(const line & FirstLine, const line & SecondLine, point &t)
{
    int m = FirstLine.A * SecondLine.B - FirstLine.B * SecondLine.A;
    if (m == 0)
    {
        if (FirstLine.C == SecondLine.C)
        {
        	return -1;
		}
		else
		{
			return 0;
		}
    }
    else
    {
        t = point((-FirstLine.C) * SecondLine.B - FirstLine.B * (-SecondLine.C), FirstLine.A * (-SecondLine.C) - (-FirstLine.C) * SecondLine.A);
    	return 1;
	}
}

line::line(int AValue, int BValue, int CValue):A(AValue),B(BValue),C(CValue)
{
};

line::~line()
{
};


#endif // !ROBOCUB_SECOND_HOMEWORK

