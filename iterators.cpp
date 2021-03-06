#include <iostream>
#include <string> 
using namespace std;

int main() {
    string someSong1 = "A Sunday Kind of Love, Etta James";
    string someSong2 = "My Way, Nina Simone";
    for (string::iterator it = someSong1.begin(); it != someSong1.end(); it++)
    {
        cout << *it;
    }
    // A Sunday Kind of Love, Etta James
    cout << endl;
    //     Return reverse iterator to reverse beginning
    // Returns a reverse iterator pointing to the last character of the string (i.e., its reverse beginning).
    // Reverse iterators iterate backwards: increasing them moves them towards the beginning of the string.
    // rbegin points to the character right before the one that would be pointed to by member end.
    for (string::reverse_iterator it = someSong2.rbegin(); it != someSong2.rend(); it++)
    {
        cout << *it;
    }
    // enomiS aniN ,yaW yM
    cout << endl;
    return 0;
}