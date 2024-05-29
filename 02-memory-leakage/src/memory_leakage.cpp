#include <cassert>
#include <iostream>

#include "../include/int_array.hpp"

using std::cout;

int main()
{
    cout << "Creating an empty array.\n";
    IntArray a{};
    cout << "a.Size() is: " << a.Size() << ".\n";
    assert(a.IsEmpty());

    cout << "----------------------------------------------------------\n";

    cout << "Creating an array containing 10 elements.\n";
    IntArray b{10};
    cout << "b.Size() is: " << b.Size() << ".\n";
    assert(!b.IsEmpty());

    cout << "----------------------------------------------------------\n";

    cout << "Getting value of array.\n";
    cout << "b[10]: " << b[9] << ".\n";

    cout << "----------------------------------------------------------\n";

    cout << "Setting value of index 9 to 25.\n";
    cout << "b[9] = 25.\n";
    b[9] = 25;

    cout << "----------------------------------------------------------\n";

    cout << "Getting value of array.\n";
    cout << "b[10]: " << b[9] << ".\n";

    return 0;
}
