#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Create tree node
struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

typedef struct treeNode node;

//Function to create a node with a value
node* createNode(val) {
    node* newnode = malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->val = val;
    return newnode;
}

//Search tree for a value
node* search(node* root, int val) {
    if (root == NULL) {
        return NULL;
    } else if (val < root->val) {
        return search(root->left, val);
    } else if(val > root->val ){
        return search(root->right, val);
    } else {
        return root;
    }
}

//Insert a new node with a given value
node* insert(node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    } else if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val ) {
        root->right = insert(root->right, val);
    }
    return root;
}

//Print out the tree in Left-Root-Right order
void inorder(node* root) {
	if(root->left) {
        printf("(");
        inorder(root->left);
        printf(")");
    }

    if (root) {
        printf(" %d ", root->val);
    }

    if (root->right) {
        printf("(");
        inorder(root->right);
        printf(")");
    }
}

//Create tree from an array of numbers
node* treeFromArray(int* array, int len) {
    node* root = NULL;
    if (len>0) {
        root = createNode(array[0]);
        for (int i = 1; i<len; i++) {
            root = insert(root, array[i]);
        }
    }

    return root;
}

//Create an array of random numbers
int* createRandomArray(int size) {
    srand(time(NULL));
    if (size<1) {return NULL;}
    
    int* arr = malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%500;
    }

    return arr;
}

node* findMinNode(node* root) {
    node* current=root;
    if (!(current->left)) {
        return current;
    } else {
        return findMinNode(current->left);
    }
}

node* delete(node* root, int val) {
    if (!root) {
        return root;
    } else if (val > root->val) {
        root->right = delete(root->right, val);
    } else if (val < root->val) {
        root->left = delete(root->left, val);
    } else {
        node* temp = NULL;
        if (!(root->left) && !(root->right)) {
            free(root);
            return temp;
        } else if (!(root->left)) {
            temp = root->right;
            free(root);
            return temp;
        } else if (!(root->right)) {
            temp = root->left;
            free(root);
            return temp;
        } else {
            node* succ = findMinNode(root);
            root->val = succ->val;
            free(succ);
        }
    }

    return root;
}

int main(int argc, char** argv) {

    int* myarr = createRandomArray(7);
    node* root = treeFromArray(myarr, 7);
    inorder(root);
    printf("\n");
    root = insert(root, 190);
    inorder(root);
    printf("\n");
    root = delete(root, 190);
    inorder(root);

    return 0;
}