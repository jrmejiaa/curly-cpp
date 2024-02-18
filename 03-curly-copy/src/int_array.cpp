#include "../include/int_array.hpp"

IntArray::IntArray(int size)
{
    if (size != 0) {
        // Remember that using the {}, we initialize the array as zero
        m_ptr  = new int[size]{};
        m_size = size;
    }
}

IntArray::IntArray(const IntArray& source) {
    if (!source.IsEmpty()) {
        m_size = source.m_size;

        // Remember {} initialize the array to zero
        m_ptr = new int[m_size]{};

        for (int i = 0; i < source.Size(); i++) {
            m_ptr[i] = source.m_ptr[i];
        }
    }
}

IntArray& IntArray::operator=(IntArray source) {
    std::swap(*this, source);
    return *this;

}

int& IntArray::operator[](int index) 
{
    if (index < 0 || index >= m_size) {
        throw IntArrayOutOfBoundsException();
    }
    return m_ptr[index];
}

std::ostream& operator<<(std::ostream& os, IntArray& a)
{
    os << "[ ";

    for (int i = 0; i < a.Size(); i++) {
        os << a[i] << " ";
    }

    os << "]";

    return os;
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
    delete[] m_ptr;
}
