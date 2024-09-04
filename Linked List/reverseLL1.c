#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head, *temp = NULL;

int createNode(){
     char ch;
     int count = 0;
    do
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
         count++;

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

    return count;
    
}

void reverse(count){
    int arr[count];
    int i = 0;
    temp =head;
    while (temp!=NULL)
    {
        arr[i] = temp->data;
        i++;
        temp = temp->next;
    }

    temp = head;
    i--;

    while (temp!=NULL)
    {
        temp->data = arr[i];
        i--;
        temp = temp->next;
    }
    
    

}

int main(){
    
    int nodeCount = createNode();
    reverse(nodeCount);
    return 0;
}