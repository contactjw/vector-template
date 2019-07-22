#ifndef SimpleVector_h
#define SimpleVector_h
#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

template <class T>
class SimpleVector
{
private:
    T *aptr;            // To point to the allocated array
    int arraySize;      // Number of elements in the array
    void memError();    // Handles memory allocation errors
    void subError();    // Handles subscripts out of range
    
public:
    // Default constructor
    SimpleVector()
    {
        aptr = 0;
        arraySize = 0;
    }
    
    // Constructor declaration
    SimpleVector(int);
    
    // Copy constructor declaration
    SimpleVector(const SimpleVector &);
    
    // Destructor declaration
    ~SimpleVector();
    
    // Accessor to return the array size
    int size() const
    {
        return arraySize;
    }
    
    // Accessor to return a specific element
    T getElementAt(int sub);
    
    // Overloaded [] operator declaration
    T &operator[](const int &);
};


template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    
    try
    {
        aptr = new T[arraySize];
    }
    catch (bad_alloc)
    {
        memError();
    }
    
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    arraySize = obj.arraySize;
    
    aptr = new T[arraySize];
    if (aptr == 0)
        memError();
    
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete [] aptr;
}

template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

#endif /* SimpleVector_h */
