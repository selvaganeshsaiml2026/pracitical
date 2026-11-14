
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int mark;
    char grade;
};

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    // Get student details from user
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << endl;

        cout << "Enter Name: ";
        cin >> students[i].name;

        cout << "Enter Mark: ";
        cin >> students[i].mark;
    }

    // Sort students by marks in descending order
    sort(students.begin(), students.end(),
    [](Student a, Student b)
    {
        return a.mark > b.mark;
    });

    // Assign grades using transform
    transform(students.begin(), students.end(),
    students.begin(),
    [](Student s)
    {
        if (s.mark >= 90)
            s.grade = 'A';
        else if (s.mark >= 75)
            s.grade = 'B';
        else if (s.mark >= 50)
            s.grade = 'C';
        else
            s.grade = 'F';

        return s;
    });

    // Find first student scoring above 80
    auto it = find_if(students.begin(), students.end(),
    [](Student s)
    {
        return s.mark > 80;
    });

    // Calculate total marks
    int total = accumulate(students.begin(), students.end(), 0,
    [](int sum, Student s)
    {
        return sum + s.mark;
    });

    // Calculate average
    float average = (float)total / students.size();

    // Display student details
    cout << "\nStudent Grade Analyzer\n";
    cout << "---------------------\n";
    cout << "Name\tMark\tGrade\n";

    for (Student s : students)
    {
        cout << s.name << "\t"
             << s.mark << "\t"
             << s.grade << endl;
    }

    if (it != students.end())
    {
        cout << "\nFirst student scoring above 80: "
             << it->name << endl;
    }
    else
    {
        cout << "\nNo student scored above 80." << endl;
    }

    cout << "Total Marks: " << total << endl;
    cout << "Average Mark: " << average << endl;

    return 0;
}
