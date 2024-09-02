#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head, *temp = NULL;

void createNode(){
     char ch;
    do
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data:\n");
        scanf("%d", &newNode->data);
        newNode ->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = head;
            
        }else{
            temp->next = newNode;  // Link the previous node to the new node
            temp = newNode;   
        }
        temp->next = NULL;

         printf("Do you want to insert a new node? y/n:\n");
        
        
        scanf(" %c", &ch);


    }  while (ch == 'y' || ch =='Y');
    
}

void issorted(){
    int x = -32768; //smallest 4 byte number
    temp = head;
    while (temp!=NULL)
    {
        if(temp->data<x){
            printf("NO the linked lIst is not sorted/n");
        }else
        {
            x =temp->data;
            temp = temp->next;
        }
        
    }
     printf("Yes the linked lIst is sorted/n");
}

int main(){
    
    createNode();
    issorted();
    return 0;
}