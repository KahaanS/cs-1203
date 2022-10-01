#include <stdio.h>
#include <stdlib.h>

//Create linked list data type
struct list_node
{
    int val;
    struct list_node* next;
};

typedef struct list_node node;

void printList(node* head) {
    while (head != NULL) {
        printf("Node: %d \n", head->val);
        head = head->next;
    }
}

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


int main() {

    //Get head of linked list
    node* head = malloc(sizeof(node));
    
    //Create list till negative value is entered
    int n;
    node* curr = NULL;
    node* nextnode = NULL;
   
    while (1) {
        printf("Enter a value \n");
        scanf("%d", &n);
        if(n<0) break;

        if (curr == NULL) {
            curr = head;
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

    printList(head);
    node** head_pointer = &head;
    
    reverseList(head_pointer);
    printList(head);

    return 0;
}