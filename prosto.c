#include <stdio.h>

int main()
{
	int *a;
	long b;

	a = malloc(sizeof(int));
	printf("%lu %lu\n", sizeof(a), sizeof(b));
	return (0);
}