#include <stdio.h>
#include <stdlib.h>

int plus(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divided(int a, int b) { return a / b; }

/* This program can't deal with unexpected operator input */
int main()
{
	int a, c;
	char b;
    int (*func[])(int, int) = {multiply, plus, plus, minus, minus, divided};
	printf("key a Function \nEX: 1 + 1\n");
	scanf("%i %c %i", &a, &b, &c);
    printf("%d %c %d = %d\n", a, b, c, (*func[b - '*'])(a, c));
    return 0;
}
