#include <iostream>
#include <cassert>

#include "../include/int_array.hpp"

using std::cout;

int main() 
{
    cout << "Creating an empty array.\n";
    IntArray a(10);
    cout << "a.Size() is: " << a.Size() << ".\n";
    assert(!a.IsEmpty());

    cout << "----------------------------------------------------------\n";
    cout << "Writing elements to a.\n";
    for (int i = 0; i < a.Size(); i++) {
        a[i] = i*2;
    }

    cout << "----------------------------------------------------------\n";
    cout << "Elements of a: " << a <<  ".\n";
    
    cout << "----------------------------------------------------------\n";

    cout << "Copying constructor a element to b.\n";
    IntArray b = a;
    assert(!b.IsEmpty());

    cout << "----------------------------------------------------------\n";

    cout << "Setting value of index 10 to 10.\n";
    cout << "b[9] = 100.\n";
    b[9] = 100;

    cout << "----------------------------------------------------------\n";
    cout << "Elements of a: " << a <<  ".\n";

    cout << "----------------------------------------------------------\n";
    cout << "Elements of b: " << b <<  ".\n";

    return 0;
}