#ifndef SearchableVector_h
#define SearchableVector_h
#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
    // Default constructor
    SearchableVector() : SimpleVector<T>()
    { }
    
    // Constructor
    SearchableVector(int size) : SimpleVector<T>(size)
    { }
    
    // Copy constructor
    SearchableVector(const SearchableVector &);
    
    // Accessor to find an item
    int findItem(const T);
};


template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector &obj) : SimpleVector<T>(obj.size())
{
    for (int count = 0; count < this->size(); count++)
        this->operator[](count) = obj[count];
}

template <class T>
int SearchableVector<T>::findItem(const T item)
{
    for (int count = 0; count <= this->size(); count++)
    {
        if (this->getElementAt(count) == item)
            return count;
    }
    return -1;
}

#endif /* SearchableVector_h */
