#pragma once

struct Node {
    char data;
    Node* next;
};

struct Stack {
    Node* head;
    char top();
    void create();
    void close();
    void push(char ch);
    char pop();
    bool isempty();
    void print();
};


void Stack::create() {
    head = NULL;
}

char Stack::top() {
    return head == NULL ? '~' : head->data; // for infix to postfix, another way?
}

void Stack::close() {
    Node* temp = NULL;
    while(head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void Stack::push(char ch) {
    Node* new_node = new Node;
    new_node->data = ch;
    new_node->next = head;
    head = new_node;
    }
char Stack::pop() {
    Node* top_node = head;
    head = head->next;
    char temp = top_node->data;
    delete top_node;
    return temp;
}

void Stack::print() {
    Node* temp = head;
    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
bool Stack::isempty() {
    return head == NULL;
}

void removeDuplicates(Stack &s) {
    Stack* new_stack = new Stack;
    new_stack->create();
    Node* ptr = s.head;
    while (ptr != NULL) {
        char new_data = ptr->data;
        new_stack->push(new_data);
        while(s.head != NULL && s.head->data == new_data) {s.pop();}
        ptr = s.head;
    }
    while(new_stack->head != NULL) {
        s.push(new_stack->pop());
    }
}