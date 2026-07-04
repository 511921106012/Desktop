#include<iostream>
using namespace std;

class polygon 
{
    protected :
    int len;
    int wid;

    public :
    polygon (int len ,int wid ): len(len),wid(wid)
    {
        cout << "polygon called";
    }
    int area() =0; // pure vitual function 

}

class triangle : public polygon
{
    public : 

    triangle(int len ,int wid): polygon(len,wid)
    {
        cout <<" triangle  called \n";

    }
    int area()
    {
    return len * wid/2;
    }
};

class rectangle : public polygon
{
    public : 

    rectangle (int len ,int wid): polygon(len,wid)
    {
        cout << "rectangle called \n";

    }
    int area()
    {
        return len * wid;
    }
};

int main()
{
    polygon *p;
    p = new triangle(5,6);
    cout << "triangle area is " << p-> area () << end1;
    delete p;

    p = new rectangle (5,6);
    cout << "Triangle is " << p-> area () << end1:
    delete p;


}