#include <array>
#include <iostream>
#include <vector>

#include "../include/resouce.hpp"

using std::array;
using std::cout;
using std::vector;

int main()
{
    vector<int> dni_numbers;

    dni_numbers.push_back(10);
    dni_numbers.push_back(50);

    cout << "---------------------------------------------" << "\n";
    cout << "PLAYING WITH INT AND VECTORS " << "\n";
    cout << "---------------------------------------------" << "\n";
    cout << "Capacity of vector: " << dni_numbers.capacity() << "\n";
    cout << "size of vector: " << dni_numbers.size() << "\n";

    cout << "---------------------------------------------" << "\n";
    cout << "PLAYING WITH RESOURCE CLASS AND VECTORS " << "\n";
    cout << "---------------------------------------------" << "\n";
    Resource r("local-vector");
    {  // Brace of internal scope
        vector<Resource> resources;
        cout << "---------------------------------------------" << "\n";
        resources.push_back(r);
        cout << "---------------------------------------------" << "\n";
        resources.push_back(Resource("first"));
        cout << "---------------------------------------------" << "\n";
        resources.push_back(Resource("second"));
        cout << "---------------------------------------------" << "\n";
    }

    cout << "---------------------------------------------" << "\n";
    cout << "PLAYING WITH RESOURCE CLASS AND ARRAYS " << "\n";
    cout << "---------------------------------------------" << "\n";
    Resource r2("local-array");
    {  // Brace of internal scope
        array<Resource, 5> resources;
        cout << "---------------------------------------------" << "\n";
        resources[0] = r2;
        cout << "---------------------------------------------" << "\n";
        resources[1] = Resource("first");
        cout << "---------------------------------------------" << "\n";
        resources[2] = Resource("second");
        cout << "---------------------------------------------" << "\n";
    }
    cout << "---------------------------------------------" << "\n";

    return 0;
}
