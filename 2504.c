#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int len, i, flag = 0, j;
	int numofArr = 0, numofSum = 0, sum = 0;
	int arr[30] = { 0, };
	int sumArr[30];
	char str[31];
	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] == '(') {
			arr[numofArr] = 2;
			numofArr++;
		}
		else if (str[i] == '[') {
			arr[numofArr] = 3;
			numofArr++;
		}
		else if (str[i] == ')') {
			if (numofArr == 0) {
				printf("0");
				return 0;
			}
			if (arr[numofArr - 1] != 2) {
				printf("0");
				return 0;
			}
			else {
				arr[numofArr - 1] = 0;
				numofArr--;
			}
		}
		else if (str[i] == ']') {
			if (numofArr == 0) {
				printf("0");
				return 0;
			}
			if (arr[numofArr - 1] != 3) {
				printf("0");
				return 0;
			}
			else {
				arr[numofArr - 1] = 0;
				numofArr--;
			}
		}
	}
	if (numofArr != 0) {
		printf("0");
		return 0;
	}
	for (i = 0; i < len; i++) {
		if (str[i] == '(') {
			arr[numofArr] = 2;
			numofArr++;
			flag = 1;
		}
		else if (str[i] == '[') {
			arr[numofArr] = 3;
			numofArr++;
			flag = 1;
		}
		else if (str[i] == ')') {
			if (flag) {
				sumArr[numofSum] = 1;
				for (j = 0; j < numofArr; j++) {
					sumArr[numofSum] *= arr[j];
				}
				numofSum++;
			}
			arr[numofArr - 1] = 0;
			numofArr--;
			flag = 0;
		}
		else if (str[i] == ']') {
			if (flag) {
				sumArr[numofSum] = 1;
				for (j = 0; j < numofArr; j++) {
					sumArr[numofSum] *= arr[j];
				}
				numofSum++;
			}
			arr[numofArr - 1] = 0;
			numofArr--;
			flag = 0;
		}
	}
	for (i = 0; i < numofSum; i++) {
		sum += sumArr[i];
	}
	printf("%d", sum);
	return 0;
}
/*
백준 2504번

내가 아는 괄호열 방식으로 했을 때는 맞음
괄호가 중간에 끼어있거나 누락되었을 경우 틀림
괄호열 방식이 잘 됐을 경우 둘이 붙어있을 때도 맞음

(()[[]])
= 2*(2+3*3)
= 2*2 + 2*3*3

괄호 안의 계산식을 다 계산하고 나서 이것을 다시 괄호 밖의 가중치와 곱하는 방식이 아닌 처음부터 가중치를 괄호 안의 식에 곱한 뒤에 계산해야 한다

1. 현재 문자가 "(" 또는 "[" 일 때 => 그냥 스택에 push한다.

2. 현재 문자가 ")"일 때

2-1. 스택이 비었을 때
=> 입력이 잘못된 경우이므로 break.

2-2. 스택의 top이 "("일 때
=> "()"이므로 스택을 한 번 pop 하고 "2"를 push한다.

2-3. 스택의 top이 숫자일 때
=> 괄호 안에 식이 있는 경우이다. 숫자가 다 떨어질 때까지, 즉 여는 괄호를 만날 때까지 해당 숫자에 가중치 2를 곱하고 임시 변수에 더해나간다.

=> 모든 숫자를 더했다면 스택에 남아있는 여는 괄호를 pop하고 임시 변수를 push한다.

=> 만약 스택이 비었거나 "["이 남아있는 경우 잘못된 입력이므로 break.

3. 현재 문자가 "]"일 때
=> 2번과 비슷하게 처리한다. 가중치는 2 대신 3을 쓰면 된다.
*/
