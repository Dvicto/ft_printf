#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include <unistd.h>

typedef struct		s_flags
{
	int				grid;//#
	int				zero;//"0"
	int				minus;//"-"
	int				plus;//"+"
	int				space;//" "
	int				l;//"l   /   ll"
	int				lbig;//"L"
	int				h;//" h     /   hh"
	int				width;
	int				precision;
}					t_flags;

union	common
{
	long double c;
	uint64_t i;
	struct s_double
	{
		unsigned long int	m:64;
		int			p:15;
		int			s:1;
	}t_double;
};

typedef struct	s_byte
{
	int				m;
	int				p;
	int				por;
	int				f;
}				t_byte;

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ss;
	size_t			i;

	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ss[i] = '\0';
		i++;
	}
}


void	*ft_memalloc(size_t size)
{
	void	*s;

	if (!(s = (void *)malloc(sizeof(*s) * (size))))
		return (NULL);
	if (s)
		ft_bzero(s, size);
	return (s);
}


char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int		arif_plus(char *s, char *s1)
{
	int i;
	int l;
	int m;

	i = 347;
	l = 0;
	while (i > -1)
	{
		m = s[i] - '0' + s1[i] - '0' + l;
		s[i] = m % 10 + '0';
		l = m / 10;
		i--;
	}
	return (l);
}

void	arif_unmoz(char *s, int a)
{
	int i;
	int l;
	int m;

	i = 347;
	l = 0;
	m = (s[i] - '0') * a;
	s[i] = ((s[i] - '0') * a) % 10 + '0';
	l = m / 10 + s[i - 1] - '0';
	while (i > 1)
	{
		i--;
		m = s[i] - '0' + l;
		s[i] = m % 10 + '0';
		l = m / 10 + s[i - 1] - '0';
	}
}

void	arif_unmoz_f(char *s, int a, int por)
{
	int i;
	int l;
	int m;

	l = 0;
	i = por - 1;
	while (i > -1)
	{
		m = (s[i] - '0') * a + l;
		s[i] = m % 10 + '0';
		l = m / 10;
		i--;
	}
}

char	*arif_degree(int base, int st)
{
	char	*s;
	int		i;

	s = (char*)malloc(sizeof(char) * 349);
	s[348] = '\0';
	memset(s, '0', 348);
	i = 347;
	if (st == 0)
	{
		s[i] = '1';
		return (s);
	}
	if (st > 0)
	{
		s[i] = '1';
		while (st > 0)
		{
			arif_unmoz(s, base);
			st--;
		}
		return (s);
	}
	return (s);
}

char	*arif_degree_f(int base, int st)
{
	int		l;
	char	*s;

	l = st;
	s = (char*)malloc(sizeof(char) * 349);
	s[348] = '\0';
	memset(s, '0', 348);
	s[st - 1] = '1';
	while (st > 0)
	{
		arif_unmoz_f(s, base, l);
		st--;
	}
	return (s);
}


void		sw_increase(char *one)
{
	char *s;

	s = (char*)malloc(sizeof(char) * 349);
	s[348] = '\0';
	memset(s, '0', 348);
	s[347] = '1';
	arif_plus(one, s);
	free(s);
}

char		*sw_round(char *two, int prec, int *f)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * 349);
	s[348] = '\0';
	memset(s, '0', 348);
	s[prec] = '5';
	*f = arif_plus(s, two);
	return (s);
}

void		set_two_continue(char **two, int prec, int *f)
{
	char *s;
	char *buf;

	s = *two;
	buf = s;
	s = sw_round(s, prec, f);
	free(buf);
	buf = s;
	s = ft_strsub(buf, 0, prec);
	*two = s;
	free(buf);
}

char		*set_two(t_byte b, union common z, int prec, int *f)
{
	char	*two;
	char	*buf;

	two = (char*)malloc(sizeof(char) * 349);
	two[348] = '\0';
	memset(two, '0', 348);
	if (b.f == 0 && z.i != 0 && z.c != DBL_MIN && z.c != -DBL_MIN)
	{
		free(two);
		two = arif_degree_f(5, -b.por);
		printf("%s\n", two);
		b.por--;
	}
	while (b.m > -1 && z.i != 0 && z.c != DBL_MIN && z.c != -DBL_MIN)
	{
		if (z.t_double.m >> b.m & 1)
		{
			buf = arif_degree_f(5, -b.por);
			arif_plus(two, buf);
			printf("%s\n", two);
			free(buf);
		}
		b.por--;
		b.m--;
	}
	set_two_continue(&two, prec, f);
	return (two);
}

char		*set_one(t_byte *b, union common z)
{
	char	*one;
	char	*buf;

	one = (char*)malloc(sizeof(char) * 349);
	one[348] = '\0';
	memset(one, '0', 348);
	if ((*b).f == 1)
	{
		free(one);
		one = arif_degree(2, (*b).por);
		printf("eto f %s\n", one);
		(*b).por--;
	}
	while ((*b).por > -1 && (*b).m > -1)
	{
		if (z.t_double.m >> (*b).m & 1)
		{
			printf("%d %d %d \n", z.t_double.m, (*b).m, z.t_double.m >> (*b).m & 1);
			buf = arif_degree(2, (*b).por);
			arif_plus(one, buf);
			printf("%s\n", one);
			free(buf);
		}
		(*b).por--;
		(*b).m--;
	}
	return (one);
}


int		sw_degree(int base, int i)
{
	int		sw;

	sw = 1;
	while (i)
	{
		sw = sw * base;
		i--;
	}
	return (sw);
}

t_byte		set_byte_srtuct(union common z)
{
	t_byte b;

	b.m = 63;
	b.p = 14;
	b.por = 0;
	while (b.p > -1)
	{
		if (z.t_double.p >> b.p & 1)
			b.por = b.por + sw_degree(2, b.p);
		b.p--;
	}
	b.por = b.por - 16383;
	if (b.por > -1)
		b.f = 1;
	else
		b.f = 0;
	printf("%d\n", b.por);
	return (b);
}

void		sw_check_sign(int *len, int *i, t_flags *l, union common z)
{
	if (z.t_double.s || l->space || l->plus)
	{
		if (z.t_double.s)
		{
			write(1, "-", 1);
			(*i)++;
			(*len)--;
			l->width--;
		}
		if (l->plus && !z.t_double.s)
		{
			write(1, "+", 1);
			(*i)++;
			(*len)--;
			l->width--;
		}
		if (l->space && !l->plus && !z.t_double.s)
		{
			write(1, " ", 1);
			(*i)++;
			(*len)--;
			l->width--;
		}
	}
}

int			sw_if_minus(int len, t_flags *l, char **num, union common z)
{
	int i;

	i = 0;
	sw_check_sign(&len, &i, l, z);
	write(1, num[0], strlen(num[0]));
	i += strlen(num[0]);
	l->width -= strlen(num[0]);
	if (l->grid)
	{
		write(1, ".", 1);
		i++;
		len--;
		l->width--;
	}
	write(1, num[1], strlen(num[1]));
	i += strlen(num[1]);
	l->width -= strlen(num[1]);
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}

int			sw_if_zero(int len, t_flags *l, char **num, union common z)
{
	int i;

	i = 0;
	sw_check_sign(&len, &i, l, z);
	while (l->width > len)
	{
		write(1, "0", 1);
		i++;
		l->width--;
	}
	write(1, num[0], strlen(num[0]));
	i += strlen(num[0]);
	l->width -= strlen(num[0]);
	if (l->grid)
	{
		write(1, ".", 1);
		i++;
		len--;
		l->width--;
	}
	write(1, num[1], strlen(num[1]));
	i += strlen(num[1]);
	l->width -= strlen(num[1]);
	return (i);
}

int			sw_if_else(int len, t_flags *l, char **num, union common z)
{
	int i;

	i = 0;
	while (l->width > len)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	sw_check_sign(&len, &i, l, z);
	write(1, num[0], strlen(num[0]));
	i += strlen(num[0]);
	l->width -= strlen(num[0]);
	if (l->grid)
	{
		write(1, ".", 1);
		i++;
		len--;
		l->width--;
	}
	write(1, num[1], strlen(num[1]));
	i += strlen(num[1]);
	l->width -= strlen(num[1]);
	return (i);
}

char		**set_num(union common z, int prec)
{
	char	**num;
	t_byte	b;
	int		f;
	char	*buf;
	int		i;

	f = 0;
	b = set_byte_srtuct(z);
	if (z.t_double.s)
		printf("1");
	else
		printf("0");
	while(b.p > -1)
	{
		if (z.t_double.p >> b.p & 1)
			printf("1");
		else
			printf("0");
		b.p--;
	}
	while(b.m > -1)
	{
		if (z.t_double.m >> b.m & 1)
			printf("1");
		else
			printf("0");
		b.m--;
	}
	printf("\n");
	b = set_byte_srtuct(z);
	num = (char **)malloc(sizeof(char *) * 2);
	num[0] = set_one(&b, z);
	if (prec >= 0)
		num[1] = set_two(b, z, prec, &f);

	if (f)
		sw_increase(num[0]);
	buf = num[0];
	i = 0;
	while (buf[i] == '0' && i < 347)
		i++;
	num[0] = ft_strsub(buf, i, 349 - i - 1);
	free(buf);
	return (num);
}

void		sw_del_ar(char ***num)
{
	if (*num)
	{
		if ((*num)[0] != NULL)
			free((*num)[0]);
		if ((*num)[1] != NULL)
			free((*num)[1]);
		free(*num);
	}
}

int main()
{
	long double a = 4.0L;
	union common	z;
	char			**num;
	int				i;
	int				len;
	t_flags *l;

	l = (t_flags *)malloc(sizeof(t_flags));
	l->lbig = 1;
	l->minus = 0;
	l->precision = -1;
	l->space = 0;
	l->width = 0;
	l->zero = 0;

	z.c = a;
	if (l->precision == -1)
		l->precision = 6;
	if (l->minus)
		l->zero = 0;
	if (l->precision > 0)
		l->grid = 1;
	num = set_num(z, l->precision);
	len = strlen(num[0]) + l->grid + l->precision;
	if ((l->plus || l->space) || z.t_double.s)
		len++;
	if (l->minus)
		i = sw_if_minus(len, l, num, z);
	else if (l->zero)
		i = sw_if_zero(len, l, num, z);
	else
		i = sw_if_else(len, l, num, z);
	sw_del_ar(&num);
	printf("\n");
	printf("%d  %d\n", sizeof(a), sizeof(z));
	return (i);
}