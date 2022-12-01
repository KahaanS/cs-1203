#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int val;
    struct list_node* next;
};

typedef struct list_node node;

node* LLStackInit() {
    node* stackhead = malloc(sizeof(node));
    stackhead->val = -1;
    stackhead->next = NULL;

    return stackhead;
}

//Same as inserting at head which I had coded before
void LLStackInsert(node** head, int val) {

    if(val<0) {
        printf("Positive values only \n");
        return;
    }

    if ((*head)->val == -1) {
        (*head)->val = val;
        return;
    }

    node* newnode = malloc(sizeof(node));
    newnode->val = val;
    newnode->next = *head;
    *head = newnode;
}

int LLStackExtract(node** head) {

    if(!(*head)) {
        return -1;
    }

    int returnval = (*head)->val;
    node* oldnode = (*head);
    (*head) = (*head)->next;
    free(oldnode);

    return returnval;
}

void freeLLStack(node* head) {
    node* prev;
    while (head) {
        prev = head;
        head = head->next;
        free(prev);
    }
}

void printList(node* head) {
    while (head != NULL) {
        printf("Node: %d \n", head->val);
        head = head->next;
    }
}

int main(){
    node* stackhead = LLStackInit();
    node** stackptr = &stackhead;

    LLStackInsert(stackptr, 10);
    LLStackInsert(stackptr, 20);
    LLStackInsert(stackptr, 30);
    LLStackInsert(stackptr, -30);

    printf("%d\n", LLStackExtract(stackptr));
    printf("%d\n", LLStackExtract(stackptr));
    printf("%d\n", LLStackExtract(stackptr));
    printf("%d\n", LLStackExtract(stackptr));

    freeLLStack(stackhead);

    
    return 1;
}
