#ifndef __RESOURCE_HPP__
#define __RESOURCE_HPP__

#include <string>

class Resource
{
   private:
    std::string m_name;

   public:
    Resource();
    Resource(std::string n);
    Resource(const Resource& r);
    Resource& operator=(const Resource& r);
    ~Resource();

    std::string GetName() const { return m_name; }
};

#endif  // __RESOURCE_HPP__
