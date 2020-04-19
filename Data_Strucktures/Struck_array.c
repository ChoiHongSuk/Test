#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef struct Student {
	int id;
	char name[32];
	char dept[32];
}Student;
typedef Student Element;
Element data[MAX_STACK_SIZE];
int top;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}
void init_stack() { top = -1; };
int is_empty() { return top == -1; };
int is_fully() { return top == MAX_STACK_SIZE - 1; };
int size() { return top + 1; };

void push(Element e) {
	if (is_fully())
		error("Stack is full!");
	data[++top] = e;
}
Element pop() {
	if (is_empty())
		error("Stack is empty");
	data[top--];
}
Element peek() {
	if (is_empty())
		error("Stack is empty");
	return data[top];
}
void print_stack(char msg[]) {
	printf("%s[%2d]= ", msg, size());
	for (int i = 0; i < size(); i++)
		printf("\n\t%-15d %-10s %-20s", data[i].id, data[i].name, data[i].dept);
	printf("\n");
}
Student get_student(int id, char name[], char dept[]) {
	Student s;
	s.id = id;
	strcpy(s.name, name);
	strcpy(s.dept, dept);
	return s;
}
void main() {
	init_stack();
	push(get_student(202013001, "Choi", "computer"));
	push(get_student(202013002, "Gang", "English"));
	push(get_student(202013003, "Junn", "language"));
	push(get_student(202013004, "Jinn", "Information"));
	print_stack("people after add 4");
	pop();
	print_stack("people after remove 1");
}
