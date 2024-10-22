// Demonstration of STL::set with Goat objects
// FUN FACT: a herd of goats is called a 'trip'
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ = 200;

int main() {
    srand(time(0));

    // first read names file and store in an array
    ifstream fin("names.txt");
    string names[SZ];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    // create a set of Goat objects
    set<Goat> trip; 
    
    // create 3 Goat objects and insert them into the set & print
    for (int i = 0; i < 3; i++) {
        Goat tmp(names[rand() % SZ], rand() % 20 + 1);
        trip.insert(tmp);
    }
    cout << "The trip has " << trip.size() << " goats:\n";
    for (auto val : trip)
        cout << "\t" << val.get_name() << endl;

    // if we use emplace(), we don't have to create the temporary
    // Goat object first; we can just provide the constructor arguments
    for (int i = 0; i < 8; i++) {
        trip.emplace(names[rand() % SZ], rand() % 20 + 1);
    }
    cout << "The trip has " << trip.size() << " goats:\n";
    // note this print method uses an iterator and references an object
    for (auto it = trip.begin(); it != trip.end(); it++)
        cout << "\t" << it->get_name() << endl;

    return 0;
}

/*
Common <set> member functions:
.begin()            // returns an iterator to the first element in the set
.clear()            // removes all elements from the set
.count(value)       // returns the number of elements matching the specified value
.emplace(args)      // constructs an element in-place and inserts it into the set
.empty()            // returns whether the set is empty
.end()              // returns an iterator to the theoretical element that follows the last element in the set
.equal_range(value) // returns a range containing all elements equal to the specified value
.erase(it)          // erases the element pointed to by the iterator
.erase(value)       // erases the element with the specified value
.find(value)        // finds an element with the specified value
.insert(value)      // inserts an element or a range of elements into the set
.lower_bound(value) // returns an iterator to the first element not less than the specified value
.max_size()         // returns the maximum number of elements that the set can hold
.size()             // returns the number of elements in the set
.swap(set)          // exchanges the contents of the set with another set
.upper_bound(value) // returns an iterator to the first element greater than the specified value
*/