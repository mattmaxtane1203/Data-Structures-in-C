// Binary Search Tree //

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct NODE{
    char name[100];
    int age; // Key < >

    struct NODE* left;
    struct NODE* right;
};

// Struct-related Functions //
NODE *createNode(char _name[], int _age){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));

    strcpy(newNode->name, _name);
    newNode->age = _age;

    newNode->left = newNode->right = NULL;

    return newNode;
}

NODE *insertNode(NODE *root, char _name[], char _age){
    if(!root){
        return createNode(_name, _age);
    } else if(_age < root->age){
        root->left = insertNode(root->left, _name, _age);
    } else if(_age > root->age){
        root->right = insertNode(root->right, _name, _age);
    }

    return root;
}

NODE *getPredecessor(NODE* root){
    root = root->left;

    while(root->right){
        root = root->right;
    }

    return root;
}

NODE *deleteNode(NODE *root, int _age){
    if(_age < root->age){
        root->left = deleteNode(root->left, _age);
    } else if(_age > root->age){
        root->right = deleteNode(root->right, _age);
    }

    else{
        if(!root->left && !root->right){ // Leaf node //
            free(root);
            root = NULL;
        } else if(!root->left || !root->right){ // One child //
            NODE *child = root->left ? root->left : root->right;

            free(root);
            root = NULL;

            return child;
        } else { // Two Childs
            NODE *predecessor = getPredecessor(root);

            root->age = predecessor->age;
            strcpy(root->name, predecessor->name);

            root->left = deleteNode(root->left, predecessor->age);
        }
    }

    return root;
}

// In order, Pre order, Post order //
// In order (Ascending order)

void inOrder(NODE *root){
    if(!root){
        return;
    }

    inOrder(root->left);
    printf("%s %d\n", root->name, root->age);
    inOrder(root->right);
}

void preOrder(NODE *root){
    if(!root){
        return;
    }

    printf("%s %d\n", root->name, root->age);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(NODE *root){
    if(!root){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%s %d\n", root->name, root->age);
}

int main(){
    struct NODE *root = NULL;

    root = insertNode(root, "JF", 10);
    root = insertNode(root, "JK", 14);
    root = insertNode(root, "LF", 18);
    root = insertNode(root, "OP", 21);
    root = insertNode(root, "QR", 23);

    inOrder(root);

    return 0;
}