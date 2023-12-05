#include <iostream>
using namespace std;

template <typename T>
class MyClass
{
public:
    MyClass(T val) : value(val) {}
    void displayValue()
    {
        cout << "Value: " << value << endl;
    }

private:
    T value;
};

int main()
{
    MyClass<int> myIntObject(10);
    MyClass<float> myFloatObject(3.14);
    MyClass<string> myStringObject("Hello World!");

    myIntObject.displayValue();
    myFloatObject.displayValue();
    myStringObject.displayValue();

    return 0;
}