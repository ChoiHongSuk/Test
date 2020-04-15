#include <stdio.h>
#include <stdlib.h>
typedef struct {
	double real;
	double imag;
}complex;
void print_complex(complex c) {
	printf("%4.1f + % 4.1fi\n",c.real,c.imag);
};
void reset_complex(complex* c) {
	c->real = c->imag = 0.0;
};
void main() {
	complex a = {1.0, 2.0};

	printf("초기화 이전: ");
	print_complex(a);
	reset_complex(&a);
	printf("초기화 이후: ");
	print_complex(a);
	return 0;
}