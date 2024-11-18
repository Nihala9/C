#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                 
    struct node *left;        
    struct node *right;      
};

struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* search(struct node*, int);
void display(struct node*);

int main() {
    int opt, data;
    struct node *start = NULL;

    do {
        printf("\nDoubly Linked List Operations\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &opt);
        
        switch(opt) {
            case 1: 
                printf("Enter the data: ");
                scanf("%d", &data);
                start = insert(start, data);
                break;
            case 2: 
                printf("Enter item to be deleted: ");
                scanf("%d", &data);
                start = delete(start, data);
                break;
            case 3: 
                printf("Enter item to search: ");
                scanf("%d", &data);
                if (search(start, data) == NULL)
                    printf("Item not found\n");
                else
                    printf("Item found\n");
                break;
            case 4: 
                display(start);
                break;
            case 5: 
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

void display(struct node *s) {
    if (s == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (s != NULL) {
        printf("%d\t", s->data);
        s = s->right;
    }
    printf("\n");
}

struct node* search(struct node *s, int data) {
    while (s != NULL && s->data != data)
        s = s->right;
    return s;
}

struct node* insert(struct node *s, int data) {  
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Memory allocation failed\n");
        return s;
    }
    t->data = data;
    t->left = NULL;
    t->right = s;
    if (s != NULL)
        s->left = t;
    return t;
}

struct node* delete(struct node *s, int data) {  
    struct node *t = search(s, data);
    if (t != NULL) {
        if (t->left == NULL && t->right == NULL) {
            s = NULL; 
        } else if (t->left == NULL) {
            s = t->right; 
            if (s != NULL) 
                s->left = NULL;
        } else if (t->right == NULL) {
            t->left->right = NULL; 
        } else {
            t->left->right = t->right;
            t->right->left = t->left;
        }
        free(t);
    } else {
        printf("Item not found\n");
    }
    return s;
}

