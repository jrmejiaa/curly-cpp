#ifndef _INT_ARRAY_INCLUDE_HPP_
#define _INT_ARRAY_INCLUDE_HPP_

#include <algorithm>
#include <iostream>

class IntArrayOutOfBoundsException : public std::exception
{
   public:
    std::string what() { return "The index is not in scope"; }
};

class IntArray
{
   private:
    /**
    * @brief Pointer with the array of ints
    * 
    */
    int* m_ptr = nullptr;
    /**
     * @brief size of the array created @ref m_ptr
     * 
     */
    int m_size = 0;

   public:
    /**
     * @brief Construct by a new IntArray object
     * 
     */
    IntArray() = default;

    /**
     * @brief Construct a new Int Array object with a certain size
     * 
     * @param size of the new object
     */
    explicit IntArray(int size);

    /**
     * @brief Destroy the IntArray object and clean all needed resources
     * 
     */
    ~IntArray();

    /**
     * @brief Copy Construct is when we have a call like: IntArray b = a;
     * 
     * The idea basically is that this should always be a deep copy. We need to avoid shallow copy, which happens often in C++ using pointers
     * 
     * @param source the original object that wants to be copied
     */
    IntArray(const IntArray& source);

    /**
     * @brief Copy Assignment is called when an already initialized object is assigned a new value from another existing object. 
     * It does not create a separate memory block or new memory space.
     * 
     * 
     * IntArray b;
     * b = a;
     * 
     * @param source object that wants to be copied
     * @return IntArray& the new object with all the copied information
     */
    IntArray& operator=(IntArray source);

    /**
     * @brief Overloading of operator to access the information of the array
     * 
     * @param index position that want to be accessed
     * @return int& value of the array in the index position
     */
    int& operator[](int index);

    /**
     * @brief Overloading to be able to use ostream to copy the information in a pretty way
     * 
     * @param os stream component 
     * @param a object that wants to be printed in the ostream object
     * @return std::ostream& stream component that has all the information from the IntArray
     */
    friend std::ostream& operator<<(std::ostream& os, IntArray& a);

    /**
     * @brief Get the size of the array
     * 
     * @return int current size of the array
     */
    int Size() const;

    /**
     * @brief Returns if the array is empty
     * 
     * @return true in case is empty
     * @return false in case there is an array created inside the object
     */
    bool IsEmpty() const;
};

#endif // _INT_ARRAY_INCLUDE_HPP_