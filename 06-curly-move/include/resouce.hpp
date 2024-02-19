#ifndef __RESOURCE_HPP__
#define __RESOURCE_HPP__

#include <string>
#include <iostream>

class Resource
{
   private:
    std::string m_name;

   public:
    Resource();
    Resource(std::string n);
    Resource(const Resource& r);
    Resource& operator=(const Resource& r);

    Resource(const Resource&& r);
    Resource& operator=(Resource&& r);
    ~Resource();

    // Operators
    bool operator>(const Resource& r) { return m_name > r.m_name; }
    bool operator<(const Resource& r) { return m_name < r.m_name; }
    bool operator==(const Resource& r) { return m_name == r.m_name; }

    friend std::ostream& operator<<(std::ostream& os, const Resource& r);

    std::string GetName() const { return m_name; }
};

#endif  // __RESOURCE_HPP__
