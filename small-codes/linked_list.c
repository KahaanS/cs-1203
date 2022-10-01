#include <stdio.h>
#include <stdlib.h>

//Create linked list data type
struct list_node {
    int val;
    struct list_node* next;
};

typedef struct list_node node;

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

void printDoubleList(doublenode* head) {
    while (head != NULL) {
        printf("Node: %d \n", head->val);
        head = head->next;
    }
}

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


int main() {

    //Get head of linked list
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


    return 0;
}