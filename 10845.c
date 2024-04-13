#include <stdio.h>
#include <string.h>
#define MAX 10001

int queue[MAX], front = 0, rear = 0;

int empty() {
    return front == rear;
}

int main() {
    int N, n;
    char cmd[6];
    scanf("%d", &N);
    while (N--) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push")) {
            scanf("%d", &n);
            queue[rear++] = n;  
        }
        else if (!strcmp(cmd, "pop")) {
            if (empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", queue[front++]);  
            }
        }
        else if (!strcmp(cmd, "size")) {
            printf("%d\n", rear - front);  
        }
        else if (!strcmp(cmd, "empty")) {
            printf("%d\n", empty());  
        }
        else if (!strcmp(cmd, "front")) {
            printf("%d\n", empty() ? -1 : queue[front]);  
        }
        else if (!strcmp(cmd, "back")) {
            printf("%d\n", empty() ? -1 : queue[rear - 1]);  
        }
    }
    return 0;
}
