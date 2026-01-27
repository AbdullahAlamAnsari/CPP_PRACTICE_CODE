#include <iostream>
using namespace std;

struct studentaddress
{
    string home;
    int house_no;
    int age;
};

struct studentid
{
    int id;
    string name;
    char grade;
    studentaddress student;

    void greeting()
    {
        cout<<"Hello World";
    }
};

int main()
{
    
    studentid newstudent = {1,"Abdullah",'A',{"Hello",13,19}};
    newstudent.greeting();
    newstudent.student.home = "new house";
    cout<<newstudent.student.home;
    cout<<newstudent.id<<endl;
    cout<<newstudent.name<<endl;
    cout<<newstudent.grade<<endl;
    studentid *ptr = &newstudent;


    newstudent.id = 19;

    cout<<ptr->grade;
    cout<<newstudent.id<<endl;  
   

}