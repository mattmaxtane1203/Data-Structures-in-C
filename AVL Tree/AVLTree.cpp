// AVL Tree //

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declare struct
struct Node{

	int data;

	// Make pointers for child
	Node *left;
	Node *right;
};

// Functions //

Node *createNode(int data){

	Node *n = (Node*)malloc(sizeof(Node));

	n->data = data;

	// Set left and right child to none
	n->left = NULL;
	n->right = NULL;

	return n;
}

int max(int a, int b){

	if(a > b){
		return a;
	} else{
		return b;
	}
}

int getHeight(Node *root){

	// Base case
	if(root == NULL){
		return NULL;
	}

	return 1 + max(getHeight(root->left), getHeight(root->right));
}

int getBalance(Node *root){

	if(root == NULL){
		return 0;
	}

	// Balance = left child height - right child height
	// Negative means heavy on the right
	// Positive means heavy on the left
	return getHeight(root->left) - getHeight(root->right);
}

Node *leftRotate(Node *root){

	Node *rightChild = root->right;
	Node *rightLeftChild = root->right->left;

	// Point right child to the parent
	rightChild->left = root;
	root->right = rightLeftChild;

	return rightChild;
}

Node *rightRotate(Node *root){

	Node *leftChild = root->left;
	Node *leftRightChild = root->left->right;

	// Point left child to the parent
	leftChild->right = root;
	root->left = leftRightChild;

	return leftChild;
}

Node *avl(Node* root){

	if(root == NULL){
		return root;
	}

	// Positive = left heavy
	// Negative = right heavy
	bool isLeftLeftCase = getBalance(root) > 1 && getBalance(root->left) >= 0;

	bool isLeftRightCase = getBalance(root) > 1 && getBalance(root->left) < 0;

	bool isRightRightCase = getBalance(root) < -1 && getBalance(root->right) <= 0;

	bool isRightLeftCase = getBalance(root) < -1 && getBalance(root->right) > 0;

	if(isLeftLeftCase){
		root = rightRotate(root);	
	}

	if(isRightRightCase){
		root = leftRotate(root);
	}

	if(isLeftRightCase){
		root->left = leftRotate(root->left);
		root = rightRotate(root);
	}

	if(isRightLeftCase){
		root->right = rightRotate(root->right);
		root = leftRotate(root);
	}

	return root;
}

Node *insert(Node *root, int data){

	// If there is no data (This is the base case)
	if(root == NULL){
		return createNode(data);
	}

	// Boolean to determine if the root is going left or right
	bool isLeft = data < root->data;
	bool isRight = data > root->data;

	if(isLeft){
		// If data is smaller than the current node
		// Move data (cursor) to the left of current node
		root->left = insert(root->left, data);
	}

	if(isRight){
		// If data is larger than the current node
		// Move data (cursor) to the right of current node
		root->right = insert(root->right, data);
	}

	return avl(root);
}

Node *getPredecessor(Node *root){

	// Base case
	if(root == NULL){
		return NULL;
	}

	// Make cursor to the left of the root;
	Node *curr = root->left;

	// While there is a node on the right of current node
	// Move the cursor
	while(curr->right){
		curr = curr->right;
	}

	return curr;
}

Node *remove(Node *root, int data){

	// If there is no data, there is nothing to remove (Base case)
	if(root == NULL){
		return NULL;
	}

	// Boolean to determine to go left or right
	bool isLeft = data < root->data;
	bool isRight = data > root->data;
	
	if(isLeft){
		root->left = remove(root->left, data);
	} else if(isRight){
		root->right = remove(root->right, data);
	} else{
		// If data is the same as the current node
		
		// Boolean to determine if the current node has two children
		bool hasTwoChilds = root->left && root->right; // Fix if doesn't work
		bool hasNoChild = (root->left == NULL) && (root->right == NULL);

		if(hasNoChild){

			// Immediately free the current node
			free(root);
			root = NULL;

		} else if(hasTwoChilds){
			
			// Get its predecessor
			Node *child = getPredecessor(root);

			// Copy the predecessor's data to the root
			root->data = child->data;
			
			// Start finding and removing the child's data again
			root->left = remove(root->left, child->data);
			// Use root->left so root doesn't get deleted

		} else{
			// Has one child only
			// Make the child the parent
			// Determine if the child is on the left or right
			// Then assign the child as the parent

			// Declare temp
			Node *child;

			// If the child is on the left
			if(root->left){
				child = root->left;
			} else{
			// If the child is on the right
				child = root->right;
			}

			free(root);
			root = child;

		}
	}
	
	return avl(root);
}

// Ways to traverse
	// In Order, Pre Order, Post Order

void preOrder (Node *root){

	// If there is no data, just return
	if(root == NULL){
		return;
	}

	// Print data
	printf("%d %d %d\n", root->data, getHeight(root), getBalance(root));

	// Go left first then right
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	
	// // Test print
	// puts("Hello World!");

	Node *root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);

	root = remove(root, 3);

	preOrder(root);

	return 0;
}
