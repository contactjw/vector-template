#include <iostream>
#include "SearchableVector.h"
using namespace std;

int main()
{
    const int SIZE = 10;
    int count;
    int result;
    
    SearchableVector<int> intTable(SIZE);
    SearchableVector<double> doubleTable(SIZE);
    
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
    cout << endl;
    cout << "These values are in doubleTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;
    
    // Search for the value 6 in intTable
    cout << "\nSearching for 6 in intTable.\n";
    result = intTable.findItem(6);
    if (result == -1)
        cout << "6 was not found in intTable.\n";
    else
        cout << "6 was found at subscript " << result << endl;
    
    
    // Search for the value 12.84 in doubleTable
    cout << "\nSearching for 12.84 in doubleTable.\n";
    result = doubleTable.findItem(12.84);
    if (result == -1)
        cout << "12.84 was not found in doubleTable.\n";
    else
        cout << "12.84 was found at subscript " << result << endl;
    cout << endl;
    
    // Adding value to end of intTable
    cout << "Adding the value 14 to intTable.\n";
    intTable.push_back(14);
    cout << "These values are now in intTable:\n";
    for (count = 0; count < intTable.size(); count++)
        cout << intTable[count] << " ";
    cout << endl;
    cout << endl;
    
    // Remove the last two values of intTable
    cout << "Removing the last two elements from intTable.\n";
    intTable.pop_back();
    intTable.pop_back();
    cout << "These values are now in intTable:\n";
    for (count = 0; count < intTable.size(); count++)
        cout << intTable[count] << " ";
    cout << endl;
    
    return 0;
}
