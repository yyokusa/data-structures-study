#pragma once

template <typename T>
struct BSTNode {
	T data;
	BSTNode *left;
	BSTNode *right;
    void initialize(T number) {
        data = number;
        left = NULL;
        right = NULL;
    }
    // void destroy();
    // void add(BSTNode*);
};

struct BSTree {
	BSTNode<int>* root;
    void initialize() {
        root = NULL;
    }
    void add_node(int number);
    void print_tree(BSTNode<int>* node);
    int find(int num);
    // BSTNode<int>* find_node(int number);
    // void add(int);
    // BSTNode* remove(int);
    // BSTNode* search(int);
    // // BSTNode* search_parent(int);
    // void print_tree();
    // BSTNode* BFS_search(int number);
    // void destroy();
};

bool addChild(BSTNode<int>* root, BSTNode<int>* p, BSTNode<int>* u);
BSTNode<int>* findLast(BSTNode<int>* tree_root, int data);
bool add(BSTNode<int>* tree_root, int data);
