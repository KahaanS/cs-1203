#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Create tree node
struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
    int height;
};

typedef struct treeNode node;

//Function to create a node with a value
node* createNode(val) {
    node* newnode = malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->val = val;
    newnode->height = 1;
    return newnode;
}

//We need this beccause null nodes don't have a height assigned
int getHeight(node* root) {
    if (!root) {
        return 0;
    }
    return root->height;
}

int getHeightDifference(node* root) {
    if(!root) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

int getMax(int a, int b) {
    if (a>=b) {
        return a;
    } else {
        return b;
    }
}

node* findMinNode(node* root) {
    node* current=root;
    if (!(current->left)) {
        return current;
    } else {
        return findMinNode(current->left);
    }
}

//Left rotate
node* leftRotate(node* root) {
    node* rightChild = root->right;
    node* leftSubChild = rightChild->left;

    rightChild->left = root;
    root->right = leftSubChild;

    root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;
    rightChild->height = getMax(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;

    return rightChild;
}

node* rightRotate(node* root) {
    node* leftChild = root->left;
    node* rightSubChild = leftChild->right;

    leftChild->right = root;
    root->left = rightSubChild;

    root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;
    leftChild->height = getMax(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    return leftChild;
}

//Check if a node is unblanced and then rotate accordingly
node* makeBalanced(node* root) {
    int balance = getHeightDifference(root);

    if (balance > 1 && getHeightDifference(root->left) >= 0) {
        return rightRotate(root);
    }
   
    if (balance < -1 && getHeightDifference(root->right) <= 0) {
        return leftRotate(root);
    }
    
    if (balance > 1 && getHeightDifference(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && getHeightDifference(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//Insert a new node with a given value
node* insert(node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    } else if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val ) {
        root->right = insert(root->right, val);
    } else {
        return root;
    }

    root->height = getMax(getHeight(root->left), getHeight(root->right))+1;

    return makeBalanced(root);
}

node* insertSimple(node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    } else if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val ) {
        root->right = insert(root->right, val);
    }
    return root;
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

    root->height = getMax(getHeight(root->left), getHeight(root->right))+1;

    return makeBalanced(root);
}

node* deleteSimple(node* root, int val) {
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

node* simpleTreeFromArray(int* array, int len) {
    node* root = NULL;
    if (len>0) {
        root = createNode(array[0]);
        for (int i = 1; i<len; i++) {
            root = insertSimple(root, array[i]);
        }
    }

    return root;
}

//Create an array of random numbers
int* createRandomArray(int size) {
    if (size<1) {return NULL;}
    
    int* arr = malloc(size*sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%1000;
    }

    return arr;
}

int main(int argc, char** argv) {

    int* myarr = createRandomArray(20);
    node* simpleroot = simpleTreeFromArray(myarr,20);
    node* root = treeFromArray(myarr, 20);
    inorder(simpleroot);
    
    printf("\n");
    inorder(root);
    printf("\n");
    
    root = insert(root, 500);
    root = insert(root, 700);
    root = insert(root, 800);
    root = insert(root, 900);
    simpleroot = insertSimple(simpleroot, 500);
    simpleroot = insertSimple(simpleroot, 700);
    simpleroot = insertSimple(simpleroot, 800);
    simpleroot = insertSimple(simpleroot, 900);
   
    inorder(simpleroot);
    printf("\n");
    inorder(root);
    printf("\n");

    root = delete(root, 500);
    simpleroot = deleteSimple(simpleroot, 500);

    inorder(simpleroot);
    printf("\n");
    inorder(root);


    return 0;
}