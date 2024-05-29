#include <iostream>

#include "../include/resouce.hpp"

using std::cout;
using std::string;

Resource::Resource()
{
    m_name = "";
    cout << "Constructing empty class \n";
}

Resource::Resource(std::string n)
{
    m_name = n;
    cout << "Constructing " << m_name << "\n";
}

Resource::Resource(const Resource& r)
{
    m_name = r.m_name;
    cout << "copy constructing " << m_name << "\n";
}

Resource& Resource::operator=(const Resource& r)
{
    m_name = r.m_name;
    cout << "copy assigning " << m_name << "\n";
    return *this;
}

Resource::~Resource()
{
    cout << "destructing " << m_name << "\n";
}
