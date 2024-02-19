#include <iostream>

#include "../include/resouce.hpp"

using std::cout;
using std::string;

Resource::Resource()
{
    m_name = "";
}

Resource::Resource(std::string n)
{
    m_name = n;
}

Resource::Resource(const Resource& r)
{
    m_name = r.m_name;
}

Resource& Resource::operator=(const Resource& r)
{
    m_name = r.m_name;
    return *this;
}

Resource::Resource(const Resource&& r)
{
    m_name = std::move(r.m_name);
}

Resource& Resource::operator=(Resource&& r)
{
    if (this != &r) {
        m_name = std::move(r.m_name);
        r.m_name.clear();
    }
    return *this;
}

Resource::~Resource() {}

std::ostream& operator<<(std::ostream& os, const Resource& r)
{
    os << "Name: " << r.m_name;
    return os;
}
