#include <iostream>
using namespace std;
// https://www.cplusplus.com/doc/tutorial/namespaces/
// from the URL above, storage part
// The storage for variables with global or namespace scope is allocated for the
//  entire duration of the program. This is known as static storage, .....
// But there is another substantial difference between variables with static storage and variables with automatic storage:
// - Variables with static storage (such as global variables) that are not explicitly initialized 
// are automatically initialized to zeroes.!!!!!!

struct node {
    node* children[3]; 
    char data;
};

void postOrderTraversal(node* root);

int main() {
    node *a = new node;
    a->data = 'a';
    node *h = new node;
    h->data = 'h';
    node *k = new node;
    k->data = 'k';
    node *r = new node;
    r->data = 'r'; 
    a->children[0] = h;
    a->children[1] = k;
    a->children[2] = r;
    node *m = new node;
    m->data = 'm';
    h->children[0] = m;
    node *b = new node;
    b->data = 'b';
    node *r2 = new node;
    r2->data = 'r';
    node *b2 = new node;
    b2->data = 'b';
    k->children[0] = b;
    k->children[1] = r2;
    k->children[2] = b2;
    node *a2 = new node;
    a2->data = 'a';
    r->children[0] = a2;
    postOrderTraversal(a);
    cout << endl;
    return 0;
}

void postOrderTraversal(node* root) {
    if (root != NULL) {
        postOrderTraversal(root->children[0]);
        postOrderTraversal(root->children[1]);
        postOrderTraversal(root->children[2]);
        cout << root->data << " ";
    }
}