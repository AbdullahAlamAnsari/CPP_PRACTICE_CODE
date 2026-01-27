#include <iostream>
using namespace std;

struct Point{
  private:
    int x, y;

  public:
  
    // Constructors
    Point(int a, int b){
        x = a;
        y = b;
    }

    // Member function
    void show(){
        cout << x << " " << y << endl;
    }

    // Destructor
    ~Point(){
        cout << "Destroyed Point Variable" << endl;
    }
};

int main(){
    // Creating Point variables using constructors
    Point s1(1, 1);
    Point s2(99, 1001);

    s1.show();
    s2.show();
    return 0;
}