#include <iostream>
using namespace std;
class Student
{
public:
    int rollNo;
    string name;
    public:

    
    Student()
    {        
        cout<<"enter roll no and name of student"<<endl;
        cin>>rollNo;
        cin>>name;
        cout << "Student object created" << endl;
    }
    
    void display()
    {
        cout << "Roll Number: " << endl;
        cin>>rollNo;
        cout << "Name: " << endl;
        cin>>name;
    }
    
    ~Student()
    {
        cout << "Student object destroyed" << endl;
    }
};
int main()
{
    Student s1;
    s1.display();
    return 0;
}
