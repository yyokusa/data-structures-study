// learning c++ <string> header
// https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1132/handouts/08-C++-Strings.pdf
#include <iostream>
#include <string> 
using namespace std;

int main() {
    string fName = "yasin";
    string lName = "yokus";
    string fullName = fName + ' ' + lName; // string concat
    string fullNameComparison = "yasin yokus";
    cout << fullName << endl;
    cout << "Are full names equal " << (fullName == fullNameComparison) << endl; // comparison
    cout << "Length of the full name is " << fullName.length() << endl; // length() member func
    cout << "Char at the index 3 is " << fullName.at(3) << endl; // boundary check
    cout << "Char at the index 3 is " << fullName[3] << endl; // no boundary check
    // str.find(key, n)starts at position nwithin strand will attempt to find keyfrom that point on.
    cout << "Find func " << fullName.find('u') << endl; // find() is overloaded, char and string
    cout << "Find func2 " << fullName.find("kus") << endl; // returns starting pos or 

    // substr
    string oldSentence;oldSentence = "The quick brown fox jumped WAY over the lazy dog";
    int len = oldSentence.length();
    cout << "Original sentence:" << oldSentence << endl;
    int found= oldSentence.find("WAY ");
    string newSentence = oldSentence.substr(0, found);
    cout << "Modified sentence: " << newSentence << endl;
    newSentence += oldSentence.substr(found+ 4);
    cout << "Completed sentence: " << newSentence << endl;
    /* 
    Original sentence: 
        The quick brown fox jumped WAY over the lazy dog
    Modified sentence:
        The quick brown fox jumped 
    Completed sentence: 
        The quick brown fox jumped over the lazy dog 
    */

    // insert and replace
    string sentence = "CS106Bsucks.";
    cout << sentence << endl;
    // Insert "kind of" at position 8 in sentencesentence.insert(7, "kind of ");
    cout << sentence << endl;
    // Replace the 10 characters "kind of su"
    // with the string "ro" in sentencesentence.replace(7, 10, "ro");
    cout << sentence << endl;



    
    // Obtaining a C-style char*from a string

    return 0;
}