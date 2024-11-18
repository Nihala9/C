#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int stack[SIZE];
int sp = -1; 

void push(int data);
int pop();
void display();

void main() {
    int opt, data;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) { 
                    printf("\nThe popped item is %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0); 
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (1);
}

void push(int data) {
    if (sp == SIZE - 1) {
        printf("Full stack\n");
    } else {
        stack[++sp] = data; 
    }
}

int pop() {
    if (sp == -1) {
        printf("Empty stack\n");
        return -1; 
    } else {
        return stack[sp--]; 
    }
}

void display() {
    if (sp == -1) {
        printf("Empty stack\n");
    } else {
        printf("Stack contents:\n");
        for (int i = sp; i >= 0; i--) { 
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
