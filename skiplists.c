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
    int firstctr = 0;
    int secondctr = 0;
    node* lastfirst = head;
    node* lastsecond = head;

    while(curr->nextarr[0] != NULL) {

        curr = curr->nextarr[0];
        firstctr++;
        secondctr++;

        if(firstctr%5 == 0) {
            lastfirst = curr;
        }

        if(secondctr%10 == 0) {
            lastsecond = curr;
        }
    }
    
    printf("%d, %d\n", val, curr->val);
    if(firstctr>=1) {
    printf("Head next: %d \n", head->nextarr[0]->val);
    }

    node* newnode = initListNode(val);
    curr->nextarr[0] = newnode;

    
    if((firstctr+1)%5 == 0){
        lastfirst->nextarr[1] = newnode;
    }

    if(firstctr>=1) {
    printf("Head next: %d \n", head->nextarr[0]->val);
    }

     if((secondctr+1)%5 == 0){
        lastsecond->nextarr[2] = newnode;
    }

     

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
    /*
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);
    insertNode(head, 8);
    insertNode(head, 8);
    insertNode(head, 10);
    */
    printListLevels(head);
    


    return 1;
}




