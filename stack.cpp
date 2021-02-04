#include <iostream>
#include <string>
#include "stack.h"
using namespace std;


int get_priority(char ch) {
    switch(ch) {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

// Infix → Postfix Conversion Algorithm using Stack
void infixToPostfix(string input) {
    Stack s;
    s.create();
    for(string::iterator it = input.begin(); it != input.end(); ++it) { // while there are more symbols to be read
        // read the next symbol
        char symbol = *it;
        switch(symbol) {
            case '(':
            {
                // paranthesis
                s.push('(');
                break;
            }
            case ')':
            {
                // paranthesis
                char ch;
                while((ch = s.pop()) != '(') {
                    cout << ch << " ";
                }
                break;
            }
            case '*':
            case '/':
            case '+':
            case '-':
            {
                // operator
                int priority = get_priority(symbol);
                while(priority <= get_priority(s.top())) {
                    cout << s.pop() << " ";
                }
                s.push(symbol);
                break;
            }
            default:
            {
                // operand
                cout << symbol << " ";
                break;
            }
        }
    }
    while (s.head != NULL) {cout << s.pop() << " ";}
    cout << endl;
}
int main() {
    // string input = "A/(B+C)-D";
    string input = "4+5*6";
    infixToPostfix(input);
    
    
    
    
    // Stack s;
    // s.create();
    // s.push('a');
    // s.push('a');
    // s.push('a');
    // s.push('a');
    // s.push('b');
    // s.push('b');
    // s.push('c');
    // s.push('d');
    // s.push('d');
    // s.push('y');
    // s.print();
    // removeDuplicates(s);
    // s.print();
    return 0;
}