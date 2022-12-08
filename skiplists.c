#include <stdio.h>
#include <stdlib.h>

//Implementation of skip lists with 3 levels (ever node, every 5th, every 10th)
struct skip_list_node {
    int val;
    struct skip_list_node* nextarr[3];
};

typedef struct skip_list_node node;

node* initListNode(int val) {
    node* node = malloc(sizeof(node));
    node->val = val;
    node->nextarr[0] = NULL;
    node->nextarr[1] = NULL;
    node->nextarr[2] = NULL;

    return node;
}

void insertNode(node* head, int val) {
    node* curr=head;
    int ctr = 0;
    node* lastfirst = head;
    node* lastsecond = head;

    while(curr->nextarr[0] != NULL) {

        curr = curr->nextarr[0];
        ctr++;

        if(ctr%5 == 0) {
            lastfirst = curr;
        }

        if(ctr%10 == 0) {
            lastsecond = curr;
        }
    }

    node* newnode = initListNode(val);
    curr->nextarr[0] = newnode;

    printf("Pointer: %p, %d \n", lastfirst->nextarr[0], lastfirst->nextarr[0]->val);
    int oldval = lastfirst->nextarr[0]->val;

    if((ctr+1)%5==0) {
        printf("Not Changed here : %p, %d \n", lastfirst->nextarr[0], lastfirst->nextarr[0]->val);
        lastfirst->nextarr[1] = newnode;
        printf("Changed here : %p, %d \n", lastfirst->nextarr[0], lastfirst->nextarr[0]->val);
    }

    //lastfirst->nextarr[0]->val = oldval;

}

void printListLevels(node* head) {
    node* curr = head;
    while (curr != NULL) {
        printf("Node: %d \n", curr->val);
        curr = curr->nextarr[0];
    }

    printf("Level 1: \n");

    curr=head;
    while(curr != NULL) {
        printf("Node: %d \n", curr->val);
        curr = curr->nextarr[1];
    }

}

int main() {
    node* head = initListNode(1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);
    insertNode(head, 8);
    insertNode(head, 9);
    insertNode(head, 10);
    insertNode(head, 11);

    printListLevels(head);    


    return 0;
}




