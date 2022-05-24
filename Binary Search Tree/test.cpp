#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{

    int value;
    Node *left, *right;
} *root = NULL;

Node *createNode(int value){

    Node *newNode = (Node*)calloc(1, sizeof(Node));

    newNode->value = value;

    return newNode;
}

Node *insert(Node *curr, Node *newNode){

    if(curr == NULL){
        return newNode;
    }

    if(newNode->value < curr->value){
        curr->left = insert(curr->left, newNode);
        return curr;
    }

    if(newNode->value >= curr->value){
        curr->right = insert(curr->right, newNode);
        return curr;
    }
}

Node *getPredecessor(Node *curr){

    curr = curr->left;
    while(curr->right != NULL){
        curr = curr->right;
    }

    return curr;
}

Node *deletes(Node *curr, int valueToDelete){

    if(curr == NULL){
        return NULL;
    }

    if(valueToDelete < curr->value){
        curr->left = deletes(curr->left, valueToDelete);
    }

    if(valueToDelete > curr->value){
        curr->right = deletes(curr->right, valueToDelete);
    }

    else{

        if(curr->left == NULL && curr->right == NULL){
            free(curr);
            curr = NULL;
            return NULL;
        }

        else if(curr->left == NULL || curr->right == NULL){

            Node *child = curr->left ? curr->left : curr->right;

            free(curr);
            curr = NULL;

            return child;
        }

        else{

            Node *predecessor = getPredecessor(curr);

            curr->value = predecessor->value;

            curr->left = deletes(curr->left, predecessor->value);
        }
    }

    return curr;
}

void inOrder(Node *curr){

    if(curr != NULL){
        inOrder(curr->left);
        printf("%d\n", curr->value);
        inOrder(curr->right);
    }
}

int main(){

    root = insert(root, createNode(8));
    root = insert(root, createNode(10));
    root = insert(root, createNode(1));
    root = insert(root, createNode(9));
    root = insert(root, createNode(5));

    inOrder(root); puts("");

    deletes(root, 8);

    inOrder(root); puts("");

    return 0;
}