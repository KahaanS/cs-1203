#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int val;
    struct list_node* next;
};

typedef struct list_node node;

node* LLQInit() {
    node* qhead = malloc(sizeof(node));
    qhead->val = -1;
    qhead->next = NULL;

    return qhead;
}

void LLQInsert(node* head, int val) {
    if(val<0) {
        printf("Positive values only \n");
        return;
    }

    if (head->val == -1) {
        head->val = val;
        return;
    }

    node* curr = head;
    while(curr->next){
        curr = curr->next;
    }

    curr->next = malloc(sizeof(node));
    curr->next->val = val;
    curr->next->next = NULL;
}

int LLQExtract(node** head) {

    if(!(*head)) {
        return -1;
    }

    int returnval = (*head)->val;
    node* oldnode = (*head);
    (*head) = (*head)->next;
    free(oldnode);

    return returnval;
}

void freeLLQ(node* head) {
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
    node* qhead = LLQInit();
    node** qptr = &qhead;

    LLQInsert(qhead, 10);
    LLQInsert(qhead, 20);
    LLQInsert(qhead, 30);
    LLQInsert(qhead, -30);

    printf("%d\n", LLQExtract(qptr));
    printf("%d\n", LLQExtract(qptr));
    printf("%d\n", LLQExtract(qptr));
    printf("%d\n", LLQExtract(qptr));

    freeLLQ(qhead);

    
    return 1;
}