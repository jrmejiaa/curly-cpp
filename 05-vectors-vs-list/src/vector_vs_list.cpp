#include <chrono>
#include <iostream>
#include <list>
#include <vector>

#include "../include/resouce.hpp"

using std::cout;
using std::list;
using std::vector;

using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::seconds;
using std::chrono::steady_clock;
using std::chrono::system_clock;

template <typename Func>
long long TimeFunc(Func f)
{

    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();

    return duration_cast<microseconds>(end - begin).count();
}

template <typename T>
void BuildContainer(const int& size, T& v)
{
    for (int i = 0; i < size; i++) {
        int r = (int)rand();
        bool inserted = false;
        for (auto it = begin(v); it != end(v); it++) {
            if (*it > r) {
                v.insert(it, r);
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            v.push_back(r);
        }
    }
}

int main(int argc, char * argv[])
{
    if (argc != 2) {
        std::cerr << "Wrong number of parameters: ./vector-vs-list <no_elements>\n";
        return -1;
    }

    int const size = std::atoi(argv[1]);

    vector<int> v;
    v.push_back(0);

    list<int> l;
    l.push_back(0);

    auto vector_us = TimeFunc([&]() { BuildContainer(size, v); });
    auto list_us = TimeFunc([&]() { BuildContainer(size, l); });

    cout << "vector time: " << vector_us << " us \n";
    cout << "list time: " << list_us << " us \n";

    return 0;
}