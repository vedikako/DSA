#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct node *next;
}*head, *temp = NULL;

void createNOde(){
    char ch;
    do
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode ->next = NULL;


        if (head == NULL)
        {
            head = newnode;
            // newnode ->next = NULL;
            
        }else{
            temp->next = newnode;  // Link the previous node to the new node
            temp = newnode;  
        }
        
    } while (ch == 'y' || ch == 'Y');
    
    
}

void display(){
    temp = head;
    
    while (temp!=NULL)
    {
        printf("%d", &temp->data);
        temp = temp->next;
    }
    
}

void insertBegining(){
    if(head == NULL){
        printf("Create a node first\n");
    }else{

        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode ->next = head;
        head = newnode;

    }
}

int main(){

    createNOde();
    insertBegining();
    display();


    return 0;
}