// stirng 

#include<iostream>
#include<string>
using namespace std;

//  one word reading 

/*int main()
{
    string name;
    cout<< "enter the number  : "<<endl;
    cout << endl;
    cin >> name;
    cout << "the name is "<< name;
} */

int main()
{
    string name;
    cout << "enter the name : "<< endl;
    getline(cin,name);
    cout << endl;
    cout << " the word is  : "<< name << endl;
}


// multiple word reading