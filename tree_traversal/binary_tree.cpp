#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include "tree.h" 
using namespace std;

//              0
//         1         2
//     3      4    5    6

int main2() {
    Tree someTree;
    build_trivial_tree(someTree);
    cout << "Bread first search: " << endl;
    breadth_first_search(someTree.root);

    /* // recursive methods
    cout << "recursive preorder: " << endl;
    recursive_preorder(someTree.root);

    cout << "recursive inorder: " << endl;
    recursive_inorder(someTree.root);

    cout << "recursive postorder: " << endl;
    recursive_postorder(someTree.root);
    
    // iterative methods
    cout << "iterative preorder: " << endl;
    iterative_preorder(someTree.root);
    
    cout << "iterative inorder: " << endl;
    iterative_inorder(someTree.root);

    cout << "iterative postorder: " << endl;
    iterative_postorder(someTree.root); */
    return 0;
}

void build_trivial_tree(Tree& someTree) {
    someTree.root = new Node;
    someTree.root->data = 0;
    someTree.root->left = new Node;
    someTree.root->right = new Node;
    someTree.root->left->data = 1;
    someTree.root->right->data = 2;
    Node* ptr_left = someTree.root->left;
    Node* ptr_right = someTree.root->right;
    ptr_left->left = new Node;
    ptr_left->right = new Node;
    ptr_left->left->data = 3;
    ptr_left->right->data = 4;
    ptr_left->left->left = NULL;
    ptr_left->left->right = NULL;
    ptr_left->right->left = NULL;
    ptr_left->right->right = NULL;
    
    ptr_right->left = new Node;
    ptr_right->right = new Node;
    ptr_right->left->data = 5;
    ptr_right->right->data = 6;
    ptr_right->left->left = NULL;
    ptr_right->left->right = NULL;
    ptr_right->right->left = NULL;
    ptr_right->right->right = NULL;
}

// left - root - right
// 1. go as left as possible
//  1.1 by pushing left child nodes into stack
// 2. if node is NULL
// 3. pop from stack, visit node, curr_node = right child
// 4. go to 1
void iterative_inorder(Node * tree_node) {
    stack<Node*> s;
    while(s.size() != 0 || tree_node != NULL) {
        if (tree_node != NULL) {
            s.push(tree_node);
            tree_node = tree_node->left;
        } else { // tree_node is NULL
            tree_node = s.top();
            s.pop();
            cout << tree_node->data << endl;
            tree_node = tree_node->right;
        }
    }
}

// root - left - right
void iterative_preorder(Node * tree_node) {
    if (tree_node == NULL) return;
    stack<Node*> s;
    s.push(tree_node);
    while(s.size() != 0) {
        Node* p_node = s.top();
        s.pop();
        cout << p_node->data << endl; // visit
        // right child is pushed first so that left is processed first
        if(p_node->right != NULL) s.push(p_node->right);
        if(p_node->left != NULL) s.push(p_node->left);
    }
}

// left - right - root
void iterative_postorder(Node * tree_node) {
    stack<Node*> s;
    Node* lastVisitedNode = NULL; // we'll use it for right child
    while(s.size() != 0 || tree_node != NULL) {
        if (tree_node != NULL) {
            s.push(tree_node);
            tree_node = tree_node->left;
        } else {
            Node* peekNode = s.top();
            // it has right child and we did not visited
            if (peekNode->right != NULL && lastVisitedNode != peekNode->right) {
                tree_node = peekNode->right;
            } else {
                // either it does not have right child
                // or we it has but we visited it
                cout << peekNode->data << endl;
                lastVisitedNode = s.top();
                s.pop();
            }
        }
    }
}

// preorder
// root - left - right
// 0 1 3 4 2 5 6
void recursive_preorder(Node * tree_node) {
    if (tree_node != NULL) {
        cout << tree_node->data << endl;
        recursive_preorder(tree_node->left);
        recursive_preorder(tree_node->right);
    }
}

// inorder
// left - root - right
// 3 1 4 0 5 2 6
void recursive_inorder(Node * tree_node) {
    if (tree_node != NULL) {
        recursive_inorder(tree_node->left);
        cout << tree_node->data << endl;
        recursive_inorder(tree_node->right);
    }
}

// postorder
// left - right root
// 3 4 1 5 6 2 0
void recursive_postorder(Node * tree_node) {
    if (tree_node != NULL) {
        recursive_postorder(tree_node->left);
        recursive_postorder(tree_node->right);
        cout << tree_node->data << endl;
    }
}

void breadth_first_search(Node* tree_node) {
    if (tree_node == NULL) return;
    // queue<Node*, deque<Node*> > q;
    queue<Node*> q;
    q.push(tree_node);
    while(q.size() != 0) {
        Node* visited_node = q.front();
        q.pop();
        cout << visited_node->data << endl;
        if(visited_node->left != NULL) 
            q.push(visited_node->left);
        if(visited_node->right != NULL) 
            q.push(visited_node->right);
    }
}

// number of nodes in tree rooted at root
int size(Node* root) {
    if (root == NULL) {return 0;}
    return 1 + size(root->left) + size(root->right);
}

// the height of a tree node
int height(Node* tree_node) {
    if (tree_node == NULL) {return -1;}
    return 1 + max(height(tree_node->left),
                     height(tree_node->right));
}

// In some implementations of binary trees, 
// the parent field is not used.
// When this is the case,  a non-recursive implementation
// is still possible,but the implementation has to use
// aList(orStack) to keep track of thepath from the 
// current node to the root.


/* 
To traverse a binary tree without recursion,
you can use an algorithm that relies on where it 
came from to determine where it will go next.

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

void traverse2(Node* root) {
    Node* current = root;
    Node* prev = NULL;
    Node* next = NULL;
    while (current != NULL) {
        if (prev == current->parent) { // came from parent
            if (current->left != NULL)
                next = current->left;
            else if (current->right != NULL) 
                next = current->right;
            else 
                next = current->parent;
        } else if (prev == current->left) { // from left
            if (current->right != NULL) 
                next = current->right;
            else 
                next = current->parent;
        } else {
            next = current->parent;
        }
        prev = current;
        current = next;
    }
}

int size2(Node* root) {
    Node* current = root;
    Node* prev = NULL;
    Node* next = NULL;
    int n = 0;
    while (current != NULL) {
        if (prev == current->parent) { // came from parent
            n++;
            if (current->left != NULL)
                next = current->left;
            else if (current->right != NULL) 
                next = current->right;
            else 
                next = current->parent;
        } else if (prev == current->left) { // from left
            if (current->right != NULL) 
                next = current->right;
            else 
                next = current->parent;
        } else {
            next = current->parent;
        }
        prev = current;
        current = next;
    }
    return n;
} */
