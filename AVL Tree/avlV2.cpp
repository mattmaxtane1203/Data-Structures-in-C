#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{

    int key;
    char name[50];
    int height;
    Node *left, *right;

} *root = NULL;

Node *createNode(int key, char *name){

    Node *newNode = (Node*)calloc(1, sizeof(Node));

    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->height = 1;

    return newNode;
}

int returnMax(int a, int b){

    if(a > b) return a;
    return b;
}

int returnHeight(Node *root){

    if(root == NULL){
        return 0;
    }

    return 1 + returnMax(returnHeight(root->left), returnHeight(root->right));
}

int returnBalance(Node *root){

    if(root == NULL){
        return 0;
    }

    return returnHeight(root->left) - returnHeight(root->right);
}

Node *rightRotate(Node *root){

    Node *leftChild = root->left;
    Node *leftRightChild = root->left->right;

    leftChild->right = root;
    root->left = leftRightChild;

    root->height = returnHeight(root);
    leftChild->height = returnHeight(leftChild);

    return leftChild;
}

Node *leftRotate(Node *root){

    Node *rightChild = root->right;
    Node *rightLeftChild = root->right->left;

    rightChild->left = root;
    root->right = rightLeftChild;

    root->height = returnHeight(root);
    rightChild->height = returnHeight(rightChild);

    return rightChild;
}

Node *insert(Node *root, int key, char *name){

    if(root == NULL){
        return createNode(key, name);
    }

    if(key < root->key){
        root->left = insert(root->left, key, name);
    } else{
        root->right = insert(root->right, key, name);
    }

    root->height = returnHeight(root);

    int balance = returnBalance(root);

    // Left Left Case
    if(balance > 1 && key < root->left->key){

        // Right Rotate
        return rightRotate(root);
    }

    // Right Right Case
    if(balance < -1 && key > root->right->key){

        // Left Rotate
        return leftRotate(root);
    }

    // Left Right Case
    if(balance > 1 && key > root->left->key){

        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if(balance < 1 && key < root->right->key){

        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *getPredecessor(Node *root){

    Node *predecessor = root->left;

    while(predecessor->right){
        predecessor = predecessor->right;
    }

    return predecessor;
}

Node *deletes(Node *root, int key){

    if(root == NULL){
        return NULL;
    }

    bool isLeft = key < root->key;
    bool isRight = key > root->key;

    if(isLeft){
        root->left = deletes(root->left, key);
    } else if(isRight){
        root->right = deletes(root->right, key);
    } else{

        bool isLeafNode = root->left == NULL && root->right == NULL;
        bool hasTwoChilds = root->left && root->right;

        if(isLeafNode){

            free(root);
            root = NULL;
        } else if(hasTwoChilds){

            Node *predecessor = getPredecessor(root);

            root->key = predecessor->key;
            strcpy(root->name, predecessor->name);

            root->left = deletes(predecessor, predecessor->key);
        } else{

            Node *child;
            if(root->right){
                child = root->right;
            } else{
                child = root->left;
            }

            return child;
        }

    }

    if(root == NULL){
        return root;
    }

    root->height = returnHeight(root);

    int balance = returnBalance(root);

    // Left Left Case
    if(balance > 1 && key < root->left->key){

        // Right Rotate
        return rightRotate(root);
    }

    // Right Right Case
    if(balance < -1 && key > root->right->key){

        // Left Rotate
        return leftRotate(root);
    }

    // Left Right Case
    if(balance > 1 && key > root->left->key){

        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if(balance < 1 && key < root->right->key){

        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *deleteAll(Node *root){

    if(root != NULL){
        deleteAll(root->left);
        deleteAll(root->right);
        root->left = root->right = NULL;
        free(root);
        root = NULL;
    }

    return root;
}

Node *findNode(Node *root, int key){

    if(root == NULL){
        return NULL;
    }

    if(root->key == key){
        return root;
    }

    if(key > root->key){
        return findNode(root->right, key);
    }

    return findNode(root->right, key);
}

void searchResult(Node *root, int key){

    Node *result = findNode(root, key);

    if(result == NULL){
        printf("Key not found!\n");
        return;
    }

    printf("%d %s, height = %d\n", root->key, root->name, root->height);
}

void viewInOrder(Node *root){

    if(root != NULL){

        viewInOrder(root->left);
        printf("%d %s, height = %d\n", root->key, root->name, root->height);
        viewInOrder(root->right);
    }
}

int main(){
    
    root = insert(root, 10, "Paul");
    root = insert(root, 5, "Erio");
    root = insert(root, 15, "Marcella");
    root = insert(root, 2, "Ray");
    root = insert(root, 1, "Samuel");

    viewInOrder(root);

    puts("");
    root = deletes(root, 15);
    viewInOrder(root);


    puts("");
    root = deletes(root, 2);
    viewInOrder(root);

    puts("");
    root = deleteAll(root);
    viewInOrder(root);
    puts("test");
    
    return 0;
}