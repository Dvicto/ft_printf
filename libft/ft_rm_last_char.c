#include "libft.h"

char	*ft_rm_last_char(char *str)
{
	char	*newstr;
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	newstr = malloc(sizeof(char *) * i);
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = str[i];		
	}
	free(str);
	return newstr;
}