#include <stdio.h>
#include <stdlib.h>

//Create linked list data type
struct list_node {
    int val;
    struct list_node* next;
};

typedef struct list_node node;

//Create doubly linked list data type
struct double_list_node {
    int val;
    struct double_list_node* next;
    struct double_list_node* prev;
};

typedef struct double_list_node doublenode;

void printList(node* head) {
    while (head != NULL) {
        printf("Node: %d \n", head->val);
        head = head->next;
    }
}

//Reverse the list
void reverseList(node** head) {
    node* currnode = *head;
    node* nextnode = NULL;
    node* prevnode = NULL;
    while (currnode != NULL) {
        nextnode = currnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }

    *head = prevnode;
}

//Print half the list using tortoise rabbit
void printHalfList(node* head) {
    node* turt = head;
    node* rab = head;
    while(rab != NULL) {
        printf("Node: %d \n", turt->val);
        turt = turt->next;
        rab = (rab->next) ? rab->next->next : NULL;
    }
}

//Create linked list from values until negative value is inputted
void createListNegative(node** head) {
    int n;
    node* curr = NULL;
    node* nextnode = NULL;
   
    while (1) {
        printf("Enter a value \n");
        scanf("%d", &n);
        if(n<0) break;

        if (curr == NULL) {
            curr = *head;
            curr->val = n;
            curr->next = NULL;
        } else {
        nextnode = malloc(sizeof(node));

        nextnode->val = n;
        nextnode->next = NULL;
        curr->next = nextnode;
        curr = curr->next;
        }

    }
}

//Create doubly linked lsit from values until negative value is inputted
void createDoubleListNegative(doublenode **head) {
    int n;
    doublenode* curr = NULL;
    doublenode* next = NULL;

    while(1) {
        printf("Enter a value \n");
        scanf("%d", &n);
        if(n<0) break;

        if (curr==NULL) {
            curr = *head;
            curr->val = n;
            curr->prev = NULL;
            curr->next = NULL;

        } else {
            next = malloc(sizeof(doublenode));

            next->val = n;
            next->prev = curr;
            next->next = NULL;
            curr->next = next;
            curr = curr->next;
        }
    }
}

//Print doubly linked list
void printDoubleList(doublenode* head) {
    while (head != NULL) {
        printf("Node: %d \n", head->val);
        head = head->next;
    }
}

//Reverse a doubly linked list
void revDoubleList(doublenode** head) {
    doublenode* curr = *head;
    doublenode* next = NULL;
    doublenode* prev = NULL;

    while (curr != NULL) {
        next = curr->next;

        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        
    }

    *head = prev;
}

//Get a node from a list
node* getNode(node* head, int pos) {
    node* getnode = head;
    for(int i=0; i<pos; i++) {
        getnode = getnode->next;
        if (getnode==NULL) {
            return NULL;
        }
    }

    return getnode;
}

//Delete a node from a list
void delNode(node** head, int pos) {
    node* delnode = getNode(*head, pos);

    if (pos==0) {
        *head = delnode->next;
        free(delnode);
    } else {
        node* prevnode = getNode(*head, pos-1);
        prevnode->next = delnode->next;
        free(delnode);
    }
}

//Get node from doubly linked list
doublenode* getDoubleNode(doublenode* head, int pos) {
    doublenode* getnode = head;
    for(int i=0; i<pos; i++) {
        getnode = getnode->next;
        if (getnode == NULL) {
            return NULL;
        }
    }

    return getnode;
}

//Delete node from doubly linked list
void delDoubleNode(doublenode** head, int pos) {
    doublenode* delnode = getDoubleNode(*head, pos);
    if (pos==0) {
        delnode->next->prev = NULL;
        *head = delnode->next;
        free(delnode);
    } else {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
        free(delnode);
    }
}

void addNodeHead(node** head, int val) {
    node* newnode = malloc(sizeof(node));
    newnode->val = val;
    newnode->next = *head;
    *head = newnode;
}

void addNodeDoubleHead(doublenode** head, int val) {
    doublenode* newnode = malloc(sizeof(doublenode));
    newnode->val = val;
    newnode->next = *head;
    newnode->prev = NULL;
    newnode->next->prev = newnode;
    *head = newnode;
}


int main() {

    /*
    node* head = malloc(sizeof(node));
    node** head_pointer = &head;

    createListNegative(head_pointer);
    printList(head);
    
    printf("\n");

    reverseList(head_pointer);
    printList(head);

    printf("\n");

    printHalfList(head);

    printf("\n");

    doublenode* doublehead = malloc(sizeof(doublenode));
    doublenode** dh_pointer = &doublehead;

    createDoubleListNegative(dh_pointer);

    printf("\n");

    printDoubleList(doublehead);

    printf("\n");

    revDoubleList(dh_pointer);
    printDoubleList(doublehead);

    delNode(head_pointer, 1);
    printList(head);

    node* rec = getNode(head, 1);
    printf("Val: %d \n", rec->val);
    

   doublenode* doublehead = malloc(sizeof(doublenode));
   doublenode** dh_p = &doublehead;

   createDoubleListNegative(dh_p);
   printDoubleList(doublehead);
   delDoubleNode(dh_p, 1);
   printDoubleList(doublehead);
    */

   

    return 0;
}