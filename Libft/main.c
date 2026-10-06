#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*
int main(void)
{
	char s[] = "ABCDE";
	char d[20];
	// char *ret_meme = ft_memmove(d, s, 3);

	*//* Overlap (copy in the same memory allocation) *//*
	char *ret_meme = ft_memmove(s + 2, s, 3);
	// char *ret_meme = memmove(s + 1, s, 4);

	printf("source:\t\t\t%s\n", s);
	printf("destination:\t%s\n", ret_meme);
	free(ret_meme);
}
*/

/*
int main(void)
{
	char	*trimmed = ft_strtrim(",   hello  ,world,  , ", " ,");
	printf("%s\n", trimmed);
	free(trimmed);
}
*/
/*
int main(void)
{
	char    **arr = ft_split("cchellocworldccis spaceccc", 'c');

	for (int i = 0; arr[i]; i++)
		printf("%s\n", arr[i]);
}
*/

#include <limits.h>
int main(void)
{
        printf("%s\n", ft_itoa(INT_MIN));
}
