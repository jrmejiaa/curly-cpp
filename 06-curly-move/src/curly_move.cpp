#include <chrono>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>

#include "../include/resouce.hpp"

using std::cout;
using std::list;
using std::string;
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
void Exercise(const int& size, string name)
{
    T v;
    using Type = typename T::value_type;

    Type res1("starting entry");
    v.push_back(res1);
    for (int i = 0; i < size; i++) {
        int r = (int)rand();
        // Generates a random string
        string s;
        int ss = r % 100;
        s.reserve(ss);
        std::generate_n(std::back_inserter(s), ss, [ss]() { return (char)('!' + ss / 2); });

        // Add new random string into the container 
        Type res(s);

        bool inserted = false;
        for (auto it = begin(v); it != end(v); it++) {
            if (*it > res) {
                v.insert(it, res);
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            v.push_back(res);
        }
    }

    auto it = std::max_element(begin(v), end(v));
    Type max_v = *it;
    it = std::min_element(begin(v), end(v));
    Type min_v = *it;

    bool sorted = std::is_sorted(begin(v), end(v));

    if (sorted) {
        v.push_back(res1);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Wrong number of parameters: ./curly-move <no_elements>\n";
        return -1;
    }

    int const size = std::atoi(argv[1]);

    auto vector_us = TimeFunc([&]() { Exercise<vector<Resource>>(size, "vector"); });
    auto list_us = TimeFunc([&]() { Exercise<list<Resource>>(size, "list"); });

    cout << "vector time: " << vector_us << " us \n";
    cout << "list time: " << list_us << " us \n";

    return 0;
}