#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	
	i = 0;
	while (s[i])
	{
		// (*f)(i, (s + 1)) same
		f(i, &s[i]);
		i++;
	}
}

/*
void change_char(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = 'X';
}

int main(void)
{
    char s[] = "abcdef";

    ft_striteri(s, change_char);
    printf("%s\n", s);
}
*/
