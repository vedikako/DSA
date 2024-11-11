#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head1 = NULL, *head2 = NULL, *temp = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createList(struct Node** head) {
    char ch;
    do {
        int data;
        printf("Enter data:\n");
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (*head == NULL) {
            *head = newNode;
            temp = *head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do you want to insert a new node? y/n:\n");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void concatenateLists(struct Node** list1, struct Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
        return;
    }

    temp = *list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
}

void display(struct Node* head) {
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Create List 1:\n");
    createList(&head1);
    printf("Create List 2:\n");
    createList(&head2);

    printf("List 1 before concatenation: ");
    display(head1);
    printf("List 2 before concatenation: ");
    display(head2);

    concatenateLists(&head1, head2);

    printf("List 1 after concatenation: ");
    display(head1);

    return 0;
}
