#pragma once

struct Node {
	int data;
	Node *left;
	Node *right;
};

struct Tree {
	Node *root;
};

void build_trivial_tree(Tree& someTree);

void recursive_preorder(Node * tree_node);
void recursive_inorder(Node * tree_node);
void recursive_postorder(Node * tree_node);

void iterative_preorder(Node * tree_node);
void iterative_inorder(Node * tree_node);
void iterative_postorder(Node * tree_node);

void breadth_first_search(Node* tree_node);

int size(Node* root);
int height(Node* tree_node);