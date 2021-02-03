#include <iostream>
#include "binary_search_tree.h"
using namespace std;
/* The data values in abinary search tree obey the binary search
tree property: For a node,u, everydata value stored in the subtree
rooted at u.left is less than u.x and every data value stored in
the subtree rooted at u.right is greater than u.x. */

void BSTree::add_node(int number) {
    if (root == NULL) {
        // cout << "add root" << endl;
        root = new BSTNode<int>;
        root->initialize(number);
        return;
    }
    BSTNode<int>* ptr = root;
    while (ptr != NULL) {
        if (ptr->data > number) { // go left
            if (ptr->left != NULL) ptr = ptr->left;
            else {
                ptr->left = new BSTNode<int>;
                ptr->left->initialize(number);
                break;
            }
        } else if (ptr->data < number) { // go right
            if (ptr->right != NULL) ptr = ptr->right;
            else {
                ptr->right = new BSTNode<int>;
                ptr->right->initialize(number);
                break;
            }
        }
    }
}

void BSTree::print_tree(BSTNode<int>* node) {
    if (node != NULL) {
        if (node->left != NULL) print_tree(node->left);
        cout << node->data << " ";
        if (node->right != NULL) print_tree(node->right);
    }
}


// find(x) operation that returns 
// the smallest value stored in the 
// tree that is greater than or equal to x
int BSTree::find(int num) {
    BSTNode<int>* ptr = root;
    BSTNode<int>* prev = NULL;
    while (ptr != NULL) {
        if (ptr->data > num) {
            prev = ptr;
            ptr = ptr->left;
        }
        else if (ptr->data < num) {
            ptr = ptr->right;
        }
        else { // if (ptr->data == num)
            ptr = ptr->right;
            return num;
        }
    }
    return prev == NULL ? -1 : prev->data;
}

// Addition
/* Different approach for adding element into BST */
bool add(BSTNode<int>* tree_root, int data) {
    BSTNode<int> *p = findLast(tree_root, data);
    BSTNode<int> *u = new BSTNode<int>;
    u->data = data;
    return addChild(tree_root, p, u);

}

BSTNode<int>* findLast(BSTNode<int>* tree_root, int data) {
    BSTNode<int>* w = tree_root;
    BSTNode<int>* prev = NULL;
    while (w != NULL)
    {
        prev = w;
        if (w->data < data) {
            w = w->right;
        } else if (w->data > data) {
            w = w->left;
        } else {
            return w;
        }
    }
    return prev;
}

bool addChild(BSTNode<int>* root, BSTNode<int>* p, BSTNode<int>* u) {
    if (p == NULL) {
        root = p; // inserting into empty tree
    }
    while (p != NULL) {
        if (p->data < u->data) {
            p = p->right;
        } else if (p->data > u->data) {
            p = p->left;
        } else {
            return false;
        }
    }
    // maybe increase tree size
    return true;
}
// Addition END

// Removal
// leaf node or node w/ one child is easy
// when removing w/ node with two child
// replace node w/ right subtree's leftmost leaf
// remove right subtree's leftmost leaf
/*
void splice(Node* u) { // called only for leaf nodes or nodes w/ single child
    Node*s,*p;
    if (u->left != nil) {
        s = u->left;
    } else { 
        s = u->right;
    } 
    if (u == r) {
        r = s;
        p = nil;
    } else {
        p = u->parent;
        if (p->left == u) {
            p->left = s;
        } else {
            p->right = s;
        }
    }
    if (s != nil) {
        s->parent = p;
    }
    n--;
}


void remove(Node*u) {
    if (u->left == nil || u->right == nil) {
        splice(u);delete u;
    } else {
        Node*w = u->right;
        while (w->left != nil)
            w = w->left;
        u->x = w->x;
        splice(w);
        delete w;
    }
}


*/

int main() {
    BSTree t;
    t.initialize();
    t.add_node(1);
    t.add_node(5);
    t.add_node(4);
    t.add_node(6);
    t.add_node(10);
    t.add_node(7);
    t.add_node(9);
    t.add_node(3);
    t.add_node(11);
    t.add_node(12);
    t.add_node(14);
    t.add_node(13);
    t.print_tree(t.root);
    cout << endl;
    cout << t.find(8) << endl;
    
    return 0;
}


/* void test_traversals();
void test_bst();


int main() {
    test_bst();
    test_traversals();
    return 0;
}

void BSTNode::initialize(int number) {
    data = number;
    left = NULL;
    right = NULL;
}

void BSTNode::destroy() {
    if(left != NULL) left->destroy();
    if(right != NULL) right->destroy();
    delete this;
}

void BSTNode::add(BSTNode* new_node) {
    if (new_node->data > data) {
        // insert right
        right = new_node;
    } else {
        // insert left
        left = new_node;
    }
}




void BSTree::initialize() {
    root = NULL;
}

void BSTree::add(int number) {
    BSTNode* new_node = new BSTNode;
    new_node->initialize(number);
    if (root == NULL) {
        root = new_node;
        return;
    }
    BSTNode* ptr = root;
    BSTNode* prev = root;
    while(ptr != NULL) {
        prev = ptr;
        if (ptr->data > new_node->data) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
    prev->add(new_node);
}

BSTNode* BSTree::remove(int number) {
    bool flag = false;
    if (number == 2) flag = true;
    if(flag) cout << "1: " << number << endl;

    if (root == NULL) {
        if(flag) cout << "2: " << number << endl;
        return NULL;
    } else if (root->data == number) {
        if(flag) cout << "3: " << number << endl;
        BSTNode* temp = root;
        root = root->left;
        return temp;
    }
    BSTNode* ptr = root;
    BSTNode* prev = root;
    while(ptr != NULL) {
        prev = ptr;
        if (ptr->data == number) {
            break;
        }
        if (ptr->data > number) {
            if(flag) cout << "4: " << number << endl;
            ptr = ptr->left;
        } else {
            if(flag) cout << "5: " << number << endl;
            ptr = ptr->right;
        }
    }
    // is ptr left or right child of prev 
    if (prev->data > ptr->data) { // left child
        prev->left = ptr->left;
        return ptr;
    } else { // right child
        prev->right = ptr->left;
        return ptr;
    }
}

BSTNode* BSTree::search(int number) {
    if (root == NULL) {
        return NULL;
    }
    BSTNode* ptr = root;
    while(ptr != NULL) {
        if (ptr->data == number) {
            return ptr;
        }
    }
    cout << "No such number" << endl;
    return NULL;
}
// BSTNode* BSTree::search_parent(int number) {}

void BSTree::print_tree() {
    // inorder traverse for ascending numbers
    stack<BSTNode*> s;
    BSTNode* ptr = root;
    while(s.size() != 0 || ptr != NULL) {
        if (ptr != NULL) {
            s.push(ptr);
            ptr = ptr->left;
        } else {
            BSTNode* top_node = s.top();
            s.pop();
            cout << top_node->data << " ";
            ptr = top_node->right;
        }
    }
    cout << endl;
}

BSTNode* BSTree::BFS_search(int number) {
    queue<BSTNode*> q;
    if (root != NULL) q.push(root);
    while(q.size() != 0) {
        BSTNode* front = q.front();
        if (front->data == number) {
            cout << "Found it " << endl;
            return front;
        } else {
            q.push(front->left);
            q.push(front->right);
        }
            q.pop();
    }
    cout << "Could not found it " << endl;
    return NULL;
}

void BSTree::destroy() {
    if (root == NULL) {
        return;
    }
    root->destroy();
} */