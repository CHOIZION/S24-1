#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int dist;
} Cell;

Cell queue[10000];
int front = 0, rear = 0;

void push(Cell c) {
    queue[rear++] = c;
}

Cell pop() {
    return queue[front++];
}

int main() {
    int N, M;
    int maze[100][100], visited[100][100] = { 0 };
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    push((Cell) { 0, 0, 1 });
    visited[0][0] = 1;

    while (front != rear) {
        Cell current = pop();
        if (current.x == N - 1 && current.y == M - 1) {
            printf("%d\n", current.dist);
            break;
        }
        for (int k = 0; k < 4; k++) {
            int nx = current.x + dx[k];
            int ny = current.y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                push((Cell) { nx, ny, current.dist + 1 });
            }
        }
    }

    return 0;
}

