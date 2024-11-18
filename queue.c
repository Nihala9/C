#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int que[SIZE];
int front = -1, rear = -1; 

void enq(int item);
int deq();
int search(int item);

void main() {
    int op, data, ans;

    do {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Your option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enq(data);
                break;

            case 2:
                data = deq();
                if (data != -1) { 
                    printf("Deleted data: %d\n", data);
                }
                break;

            case 3:
                printf("Item to search: ");
                scanf("%d", &data);
                ans = search(data);
                if (ans == 1)
                    printf("Item found\n");
                else
                    printf("Item not found\n");
                break;

            case 4:
                exit(0); 

            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (1);
}

void enq(int item) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0; 
        que[++rear] = item; 
    }
}

int deq() {
    if (front == -1 || front > rear) { 
        printf("Queue is empty\n");
        return -1; 
    }
    return que[front++]; 
}

int search(int item) {
    if (front == -1 || front > rear) {
        return 0; 
    }

    for (int i = front; i <= rear; i++) {
        if (que[i] == item) {
            return 1; 
        }
    }
    return 0; 
}

