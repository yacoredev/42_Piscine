#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	if (dsize)
	{
		i = 0;
		while(src[i] && i < dsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}


/*int     main(void)
{
    unsigned int sizeDest = 6;
    char src[] = "hello";
    char dest[sizeDest];

    unsigned int lenSrc = ft_strlcpy(dest, src, sizeDest);

    if (lenSrc < sizeDest)

        printf("%d chars successfully copied\n", lenSrc);
    // if lenSrc == sizeDest mab9atch blasa fi nzid '\0' so we hava a trun..
    else if (lenSrc >= sizeDest)
        printf("truncation happened\n");

    return(0);
}*/
