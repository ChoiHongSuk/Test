#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef int Element;
Element data[MAX_STACK_SIZE];
int top;

void error(char str[]) {
	printf("%s", str);
	exit(1);
}
void init_stack() { top = -1; };
int is_fully() { return top == MAX_STACK_SIZE - 1; };
int is_empty() { return top == -1; };
int size() { return top+1; };
void push(Element e) {
	if (is_fully())
		error("Full!");
	data[++top]=e;
}
Element pop() {
	if (is_empty())
		error("Empty!");
	return data[top--];
}
Element peek() {
	if (is_empty())
		error("Empty!");
	return data[top];
}
int check_matching(char expr[]) {
	int i=0, prev;
	char ch;
	init_stack();
	while (expr[i] != NULL) {
		ch = expr[i++];
		if (ch == '[' || ch == '{' || ch == '(')
			push(ch);
		else if (ch == ']' || ch == '}' || ch == '(') {
			if (is_empty())
				return 2;
			prev = pop();
			if ((ch == ']' && prev != '[') || (ch == '}' && prev != '{') || (ch == ')' && prev != '('))
				return 3;
		}
	}
	if (is_empty() == 0)
		return 1;
	return 0;
}
void main() {
	char expr[4][80] = { "{A[(i+1)]=0;}", "if((i==0)&&(j==0))", "A[(i+1])=0;", "A[i] =f)(;" };
	int errCode;
	for (int i = 0; i < 4; i++) {
		errCode = check_matching(i);
		if (errCode == 0)
			printf("Normal: %s\n", expr[i]);
		else
			printf("Error: %s (case%d err)\n",expr[i],errCode);
	}
}