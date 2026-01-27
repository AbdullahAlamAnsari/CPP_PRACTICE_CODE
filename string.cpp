#include <iostream>
#include <string>
using namespace std;

struct hello
{
    int a ;
    string b;
};

int main()
{
    cout<<sizeof(hello);
    string c;
    int a;
    cout<<sizeof(a);
    cout<<sizeof(c);
}