#include <iostream>
using namespace std;

struct studentid
{
    int id;
    string name;
    char grade;

    struct studentid *link;
};
int main()
{
    studentid newstudent1 = {1,"Abdullah",'A',NULL};
    studentid newstudent2 = {2,"Abdullah2",'A',NULL};
    
    newstudent1.link = &newstudent2;
    cout<<newstudent1.link->name;
}