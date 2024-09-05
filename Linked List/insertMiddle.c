#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct node *next;
}*head, *temp = NULL;

int createNOde(){
    char ch;
    int count = 0;
    do
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

        count ++;

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
    
    return count;
}

void display(){
    temp = head;
    
    while (temp!=NULL)
    {
        printf("%d", &temp->data);
        temp = temp->next;
    }
    
}

void insertMiddle(int value){
    int num;
    if(head == NULL){
        printf("Create a node first\n");
    }else{

        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode ->next = NULL;
        
        printf("Enter the positionu wanna insert:\n");
        scanf("%d", &num);

         if (num < 1 || num > value + 1) {
            printf("Invalid position\n");  
            return;
        }

        temp = head;
        for (int i = 1; i <= num-1; i++)
        {
            
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        
    }
}

int main(){

    int value = createNOde();
    insertMiddle(value);
    display();


    return 0;
}