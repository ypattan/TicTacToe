#include <iostream>
using namespace std;

class Vec{
public:
	float x,y;
	Vec(){}

Vec(float a,float b){
	x = a;
	y = b;
}

void print(){
	cout <<"("<<x<<","<<y<<")";
}
};

struct Rect{
public:
	Vec a,b,c,d;

    Rect(float x1,float y1, float h, float w){
        a.x=x1;
        a.y=y1;

        b.x = x1+w;
        b.y = y1;

        c.x = x1+w;
        c.y = y1-h;

        d.x = x1;
        d.y = y1-h;
    }
    

    void print(){
        a.print();
        b.print();
        c.print();
        d.print();
    }

    bool contains(Vec v){
        float x=v.x;
        float y=v.y;
        float x1; float y1; float x2; float y2; float x3; float y3; float x4; float y4;
        x1 = b.x; y1 = b.y;
        x2 = c.x; y2 = c.y;
        x3 = d.x; y3 = d.y;
        x4 = a.x; y4 = a.y;
        return check(x1,y1, x2,y2, x3,y3, x4,y4,x,y);
    }

    float area(float x1, float y1, float x2, float y2, float x3, float y3){
        float area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
        if(area<0.0f){
            area *= -1.0f;
        }
        return area;
    }

    bool check(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float x, float y){
        float A = area(x1, y1, x2, y2, x3, y3) + area(x1, y1, x4, y4, x3, y3);
        float A1 = area(x, y, x1, y1, x2, y2);
        float A2 = area(x, y, x2, y2, x3, y3);
        float A3 = area(x, y, x3, y3, x4, y4);
        float A4 = area(x, y, x1, y1, x4, y4);

        return (A == A1 + A2 + A3 + A4);
    }

};
