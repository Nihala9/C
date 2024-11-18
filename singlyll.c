#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node* next;
};


struct node* insert(struct node* s, int item);
struct node* delete_node(struct node* s);
void display(struct node* s);

int main() {
    struct node* start = NULL; 
    int data, opt;

    do {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                start = insert(start, data);
                break;
            case 2:
                start = delete_node(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (1);

    return 0; 
}

struct node* insert(struct node* s, int item) {
    struct node* t = (struct node*)malloc(sizeof(struct node)); 
    t->data = item; 
    t->next = s; 
    return t; 
}

struct node* delete_node(struct node* s) {
    if (s != NULL) {
        struct node* t = s;
        printf("%d is deleted\n", s->data);
        s = s->next; 
        free(t); 
        return s; 
    }
    printf("Empty list\n");
    return s; 
}

void display(struct node* s) {
    if (s == NULL) {
        printf("List is empty\n");
        return;
    }
    while (s != NULL) {
        printf("%d\t", s->data);
        s = s->next;
    }
    printf("\n");
}

