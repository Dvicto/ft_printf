#include <stdio.h>
#include <stdint.h>

union common
{
	double c;
	int64_t i;
	struct s_double
	{
		long int	m:52;
		int			p:11;
		int			s:1;
	}t_double;
};

int main()
{
	double x = 6.0;
	union common z;
	int sw = 63;

	z.c = x;

	while(sw > -1)
	{
		printf("%d", z.i >> sw & 1);
		sw--;
	}

	
	int m = 51;
	int p = 10;
	int s = 0;
	printf("\ns = ");
	printf("%d", z.t_double.s & 1);
	printf("\np = ");
	while (p > -1)
	{
		printf("%d", z.t_double.p >> p & 1);
		p--;
	}
	printf("\nm = ");
	while (m > -1)
	{
		printf("%d", z.t_double.m >> m & 1);
		m--;
	}
	printf("\n");
	return (0);
}