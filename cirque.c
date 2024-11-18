#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int que[SIZE];
int front = 0, rear = 0; 

void enq(int data);
int deque();
int search(int data);

void main() {
    int op, data;

    do {
        printf("\nCircular Queue Operation\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        printf("Your option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                enq(data);
                break;

            case 2:
                data = deque();
                if (data != -1) { 
                    printf("Deleted item is %d\n", data);
                }
                break;

            case 3:
                printf("Item to search: ");
                scanf("%d", &data);
                if (search(data)) {
                    printf("Item found\n");
                } else {
                    printf("Item not found\n");
                }
                break;

            case 4:
                exit(0); 

            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (1);
}

void enq(int data) {
    int trear = (rear + 1) % SIZE; 
    if (trear == front) { 
        printf("Queue is full\n");
    } else {
        rear = trear; 
        que[rear] = data; 
    }
}

int deque() {
    if (rear == front) { 
        printf("Queue is empty\n");
        return -1;
    } else {
        front = (front + 1) % SIZE; 
        return que[front]; 
    }
}

int search(int data) {
    if (front == rear) { 
        return 0;
    }

    int tfront = (front + 1) % SIZE; 
    while (tfront != rear && que[tfront] != data) {
        tfront = (tfront + 1) % SIZE; 
    }

    if (que[tfront] == data) {
        return 1; 
    }
    return 0; 
}
