#include <stdio.h>

void hanoi(int n, int start, int end, int via) {
    if (n == 1) {
        printf("%d %d\n", start, end);
        return;
    }
    hanoi(n - 1, start, via, end);
    printf("%d %d\n", start, end);
    hanoi(n - 1, via, end, start);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", (1 << N) - 1);
    hanoi(N, 1, 3, 2);
    return 0;
}