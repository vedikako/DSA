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

void reverse(){
    struct Node *q, *r = NULL;
    temp = head;

    while (temp!=NULL)
    {
        r = q;
        q = temp;
        temp = temp->next;
        q->next = r;
    }
    
    head = q;
    
}

int main(){
    
    createNode();
    reverse();
    return 0;
}