#include <iostream>
using namespace std;
struct point
{
    int x,y;
    int area()
    {
        return x*y;
    }
};
 
int main()
{
    point p = {1,2};    
    cout<<p.area();
}