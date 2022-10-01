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
        printf("Value: %d \n", head->val);
        head = head->next;
    }
}


int main() {

    //Get head of linked list
    node* head = malloc(sizeof(node));
    
    //Create list till negative value is entered
    int n;
    node* curr = head;
   
    while (1) {
        printf("Enter a value \n");
        scanf("%d", &n);
        if(n<0) break;

        curr
    }
    curr->next = NULL;

    printList(head);

    return 0;
}