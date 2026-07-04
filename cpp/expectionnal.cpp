#include<iostream>
using namespace std;
// over load constructor
class my_string
{
    char *data ;
    int len ;

    public;
    my_string(const char *ptr = ""): data (ptr)
    {
        len = strlen(ptr);
        data = new char [len+1];
        strcpy(data,ptr);




    }

    my_string (const my_string& s)
    {
        len = s.len;
        data = new char [len];
        strcpy(data,S.data);
        
    }
    void print()
    {
        cout << data << end1;
    }

    char& operator [] (int i)
    {
        return daa[i] // save the memory we are using 
    }

    void append (const char *str)
    {
        int l = strlen(str);
        len = l+len;
        char *temp = new char[len];
        strcpy(temp,data);
        strcat(temp,str);
        delete []data;
        data = temp;



    }

    my_string()
    {
        delete []data;
        cout << "dstr called\n;"
    }
};
int main()
{
    my_string s1 ("hello");

    s1. printf();

    s1[1] = 'A';
    s1.print();

    s1.append("world");


}