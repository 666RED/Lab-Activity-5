

// Circular linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

void sortedInsert(node**, node*);
void printList(node*);

int main(){
    int arr[] = {12, 56, 2, 11, 1, 90};
    int listSize = 6;

    node* head = NULL;
    node* temp;

    for(int i = 0; i < listSize; i++){
        temp = (node*)malloc(sizeof(node));
        temp->data = arr[i];
        sortedInsert(&head, temp);
    }
    printList(head);
    return 0;
}

void sortedInsert(node** head, node* temp){
    node* current = *head;

    if(current == NULL){ // point the first node to itself
        temp->next = temp;
        *head = temp;
    }else if(current->data >= temp->data){
        while(current->next != *head){ // moving to the last node
            current = current->next;
        }
        current->next = temp; // last node point to first node
        temp->next = *head; // first node point to second node
        *head = temp; // head point to first node
    }else{
        while(current->next != *head && current->next->data < temp->data){
            current = current->next;// moving to the node that has the value lower than the new node
        }
        temp->next = current->next; // new node point to next node
        current->next = temp; // previous node point to new node
    }
}
void printList(node* head){
    node* temp;
    if(head != NULL){
        temp = head;
        printf("Sorted List: ");
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("\n");
    }
}























