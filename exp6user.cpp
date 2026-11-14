
#include <iostream>
#include <memory>
using namespace std;

// Resource class
class Resource
{
public:
    Resource()
    {
        cout << "Resource acquired" << endl;
    }

    ~Resource()
    {
        cout << "Resource released" << endl;
    }

    void use()
    {
        cout << "Resource is being used" << endl;
    }
};

// Manual Smart Pointer using RAII
class MySmartPointer
{
private:
    Resource* ptr;

public:
    MySmartPointer(Resource* p)
    {
        ptr = p;
    }

    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual smart pointer destroyed" << endl;
    }

    Resource* operator->()
    {
        return ptr;
    }

    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;
};

int main()
{
    int choice;

    cout << "Choose Smart Pointer Type:" << endl;
    cout << "1. Manual RAII Smart Pointer" << endl;
    cout << "2. unique_ptr" << endl;
    cout << "3. shared_ptr" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            cout << "\n----- Manual RAII Smart Pointer -----" << endl;
            MySmartPointer smartPtr(new Resource());
            smartPtr->use();
            break;
        }

        case 2:
        {
            cout << "\n----- unique_ptr -----" << endl;
            unique_ptr<Resource> uniquePtr =
                make_unique<Resource>();
            uniquePtr->use();
            break;
        }

        case 3:
        {
            cout << "\n----- shared_ptr -----" << endl;
            shared_ptr<Resource> sharedPtr1 =
                make_shared<Resource>();

            shared_ptr<Resource> sharedPtr2 = sharedPtr1;

            sharedPtr1->use();

            cout << "Shared Pointer Count: "
                 << sharedPtr1.use_count() << endl;
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    cout << "\nProgram completed successfully." << endl;

    return 0;
}
