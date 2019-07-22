#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
    const int SIZE = 10;
    int count;
    
    SimpleVector<int> intTable(SIZE);
    SimpleVector<double> doubleTable(SIZE);
    
    // Store values in the two SimpleVectors
    for (count = 0; count < SIZE; count ++)
    {
        intTable[count] = (count * 2);
        doubleTable[count] = (count * 2.14);
    }
    
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl;
    cout << "These values are in doubleTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;
    
    
    return 0;
}
