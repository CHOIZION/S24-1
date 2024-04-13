#include <stdio.h>

char stack[50];
int top = 0;

int isVPS(char*);

void push(char);
char pop();
int isEmpty();

int main() {

	int t;
	char str[51];

	int i;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%s", str);

		if (isVPS(str)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;

}

int isVPS(char* str) {

	int result = 1;

	int i;

	for (i = 0; str[i]; i++) {

		if (str[i] == '(') {
			push(str[i]);
		}
		else {

			if (isEmpty()) {
				result = 0;
				break;
			}
			else {
				pop();
			}

		}

	}

	if (!isEmpty()) result = 0;

	while (!isEmpty()) {
		pop();
	}

	return result;

}

void push(char c) {
	stack[top++] = c;
}

char pop() {
	return stack[--top];
}

int isEmpty() {
	return top == 0;
}

/*9012번 괄호 문제

*스택은 후입선출임을 기억하자.*


괄호의 짝이 잘 맞는지 확인하는 문제 (어떤 방식으로든 열린 괄호와 닫힌 괄호가 잘 짝지어지기만 하면 된다.)


1. isVPS 괄호를 검사하는 함수

2. 열린 괄호일 경우 push 함수를 사용하여 스택에 추가한다.

3. 닫힌 괄호일 경우 스택이 비어있는지 확인한다.

3-1. 만약 비어있다면 반복을 중지한다.

4. 비어있지 않다면 pop 함수를 통해 스택에서 괄호를 제거한다.

5. 스택이 비어있는지 확인한다.

5-1. 만약 비어있지 않다면 유효하지 않은 괄호 문자열이다.

6. pop을 사용하여 스택을 지운다.*/