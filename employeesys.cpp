#include <iostream>
using namespace std;


class Employee
{
    protected:
    int id;
    string name;

    public:

    Employee(string name,int id)
    {
        this->name = name;
        this->id = id;
    }

};

class Developer : public Employee
{
    private:
    string language;
    public:


    Developer(string name,int id,string language) : Employee(name,id)
    {
        this->name = name;
        this->id = id;
        this->language = language;
    }

    void developerinfo()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Language: "<<language<<endl;
    }
};

int main()
{
    int capacity = 2;
    int count = 0;
    Developer** developerdata = new Developer*[capacity];
    int i = count;
    
        developerdata[0] = new Developer("Rohit",++count,"Cpp"); 
        developerdata[0]->developerinfo();
        developerdata[1] = new Developer("Rohit",++count,"Cpp");
        developerdata[1]->developerinfo();
cout<<count;

    
    
}