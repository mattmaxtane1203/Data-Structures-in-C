#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct
struct Node{

    int value;

    Node *left, *right;
} *root = NULL;

// Constructor
Node *createNode(int _value){

    // Allocate memory
    Node *newNode = (Node*)calloc(1, sizeof(Node));

    // Store information
    newNode->value = _value;

    return newNode;
}

// Insert to Binary Tree
Node *insertNode(Node *parent, Node *node){

    // Base case - return if there is no node in current position
    if(!parent){
        return node;
    }

    // If value is smaller, go left
    if(node->value < parent->value){
        parent->left = insertNode(parent->left, node);
    }

    // If value is larger, go right
    if(node->value >= parent->value){
        parent->right = insertNode(parent->right, node);
    }

    return parent;
}

Node *getPredecessor(Node *parent){

    // Set parent to the left of current position
    parent = parent->left;

    // Move right while right of current position has a node
    while(parent->right){
        parent = parent->right;
    }

    return parent;
}

Node *deleteNode(Node *parent, int _value){

    // If value does not exist
    if(parent == NULL){
        return NULL;
    }

    // If value is smaller than parent's value, move left
    if(_value < parent->value){
        parent->left = deleteNode(parent->left, _value);
    }

    // If value is larger than parent's value, move right
    else if(_value > parent->value){
        parent->right = deleteNode(parent->right, _value);
    }

    else{
        // If leaf node, immediately free and set current position as NULL
        if(!parent->left && !parent->right){
            free(parent);
            parent = NULL;
        }

        // If it has one child, store child information and return the child in its current position
        else if(!parent->left || !parent->right){

            // Store child information
            Node *child;
            if(parent->left){
                child = parent->left;
            } else{
                child = parent->right;
            }

            free(parent);
            parent = NULL;

            return child;
        }

        else{

            // If it has two children, get the predecessor and store the information in current position
            Node *predecessor = getPredecessor(parent);
    
            // Copy predecessor information
            parent->value = predecessor->value;
    
            // Proceed to delete the predecessor node from binary tree
            parent->left = deleteNode(parent->left, predecessor->value);
        }
    }

    return parent;
}

// Tree Traversal
void inOrder(Node *parent){
    
    if(parent != NULL){
        inOrder(parent->left);
        printf("%d\n", parent->value);
        inOrder(parent->right);
    }
}

void preOrder(Node *parent){

    if(parent != NULL){
        printf("%d\n", parent->value);
        preOrder(parent->left);
        preOrder(parent->right);
    }
}

void postOrder(Node *parent){

    if(parent != NULL){
        postOrder(parent->left);
        postOrder(parent->right);
        printf("%d\n", parent->value);
    }
}

void searchNode(Node *parent, int _value){

    if(!parent){
        printf("%d not found!\n", _value);
        return;
    }

    if(_value == parent->value){
        printf("%d found!\n", _value);
        return;
    }

    if(_value < parent->value){
        searchNode(parent->left, _value);
        return;
    }

    if(_value > parent->value){
        searchNode(parent->right, _value);
        return;
    }
}

int main(){

    root = insertNode(root, createNode(15));
    root = insertNode(root, createNode(26));
    root = insertNode(root, createNode(33));
    root = insertNode(root, createNode(1));
    root = insertNode(root, createNode(10));
    root = insertNode(root, createNode(70));
    root = insertNode(root, createNode(12));
    root = insertNode(root, createNode(18));
    root = insertNode(root, createNode(56));
    root = insertNode(root, createNode(99));

    postOrder(root);

    return 0;
}