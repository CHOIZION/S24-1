#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10001

int stack[MAX_STACK_SIZE];
int topIndex = -1;

void push(int value) {
    if (topIndex < MAX_STACK_SIZE - 1) {
        stack[++topIndex] = value;
    }
}

int pop() {
    if (topIndex == -1) {
        return -1;
    }
    else {
        return stack[topIndex--];
    }
}

int getSize() {
    return topIndex + 1;
}

int isEmpty() {
    return topIndex == -1 ? 1 : 0;
}

int getTop() {
    if (topIndex == -1) {
        return -1;
    }
    else {
        return stack[topIndex];
    }
}

int main() {
    int nCommands, value;
    char command[6];
    scanf("%d", &nCommands);

    while (nCommands--) {
        scanf("%s", command);
        if (!strcmp(command, "push")) {
            scanf("%d", &value);
            push(value);
        }
        else if (!strcmp(command, "pop")) {
            printf("%d\n", pop());
        }
        else if (!strcmp(command, "size")) {
            printf("%d\n", getSize());
        }
        else if (!strcmp(command, "empty")) {
            printf("%d\n", isEmpty());
        }
        else if (!strcmp(command, "top")) {
            printf("%d\n", getTop());
        }
    }

    return 0;
}
