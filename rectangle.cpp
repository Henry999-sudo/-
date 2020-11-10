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
    point();
    ~point();
    point & operator = (const point &p); 
    inline void print(){
    	cout << "(" << x << "," << y << ")";
	}
	friend class line;
	friend class rectangle;
};
point::point()
{
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
    line();
    ~line();
    friend int Intersection(const line & FirstLine, const line & SecondLine, point &t);
    line & operator = (const line & l);
};

/**
 * return : -1代表无数个交点，0代表没有交点，1代表一个交点 
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

line & line::operator = (const line & l)
{
	A = l.A;
	B = l.B;
	C = l.C;
}

line::line()
{
};

line::line(int AValue, int BValue, int CValue):A(AValue),B(BValue),C(CValue)
{
};

line::~line()
{
};
////////////////////////////////////////////////////////////////////////////////////

class rectangle
{
private:
	point lLim;
	point rLim;
			
public:
	line leftX;
	line rightX;
	line topY;
	line floorY;
	rectangle(point l,point r);
	rectangle(int xL, int yL, int xR, int yR);
	~rectangle();
	
	int Intersection_rectangle(const line & line, point *p);
};

//左下右上两个点 
rectangle::rectangle(point l, point r)
{
	lLim = l;
	rLim = r;
	
	line tLeftLim_x (lLim.x, 0, 0);
	line tRightLim_x (rLim.x, 0, 0);
	line tLeftLim_y (0, lLim.y, 0);
	line tRightLim_y (0, rLim.y, 0);
	
	leftX = tLeftLim_x;
	rightX = tRightLim_x;
	topY = tRightLim_y;
	floorY = tLeftLim_y;	
};

rectangle::rectangle(int xL, int yL, int xR, int yR)
{
	point l (xL, yL);
	point r (xR, yR);
	
	lLim = l;
	rLim = r;
	
	line tLeftLim_x (lLim.x, 0, 0);
	line tRightLim_x (rLim.x, 0, 0);
	line tLeftLim_y (0, lLim.y, 0);
	line tRightLim_y (0, rLim.y, 0);
	
	leftX = tLeftLim_x;
	rightX = tRightLim_x;
	topY = tLeftLim_y;
	floorY = tRightLim_y;	
}

rectangle::~rectangle()
{
};

int rectangle::Intersection_rectangle(const line & line, point *p)
{
	point t[4] = {point(0,0),point(0,0),point(0,0),point(0,0)};
	
	if (Intersection(line,leftX,t[0]) == -1)
	{
		return -1;
	}
	if (Intersection(line,rightX,t[1]) == -1)
	{
		return -1;
	}
	if (Intersection(line,topY,t[2]) == -1)
	{
		return -1;
	}
	if (Intersection(line,floorY,t[3]) == -1)
	{
		return -1;
	}

	int m = 0;
	int flag[] = {0};
	if (t[0].y >= lLim.y && t[0].y <= rLim.y)
	{
		flag[0] = 1;
		m++;
	}
	
	if (t[1].y >= lLim.y && t[1].y <= rLim.y)
	{
		flag[1] = 1;
		m++;
	}
	
	if (t[2].x >= lLim.x && t[2].y <= rLim.x)
	{
		flag[2] = 1;
		m++;
	}
	
	if (t[3].x >= lLim.x && t[3].x <= rLim.x)
	{
		flag[3] = 1;
		m++;
	}
	
	int j = 0;
	for (int i = 0;i < 4;++i)
	{
		if (flag[i])
		{
			p[j] = t[i];
			j++;
		}
	}
	
	return m;	 
}

#endif // !ROBOCUB_SECOND_HOMEWORK
int main()
{
	rectangle r (0,0,1,1);	
} 
