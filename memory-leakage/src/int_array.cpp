#include "../include/int_array.hpp"

IntArray::IntArray(int size)
{
    if (size != 0) {
        // Remember that using the {}, we initialize the array as zero
        m_ptr  = new int[size]{};
        m_size = size;
    }
}

int& IntArray::operator[](int index) 
{
    if (index < 0 || index >= m_size) {
        throw IntArrayOutOfBoundsException();
    }
    return m_ptr[index];
}

int IntArray::Size() const
{
    return m_size;
}

bool IntArray::IsEmpty() const
{
    return (m_size == 0);
}

IntArray::~IntArray() {
    // Uncomment this lines to remove the Memory Leak
    // delete[] m_ptr;
}
