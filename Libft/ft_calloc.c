#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	nbr_bytes;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		nbr_bytes = 1;
	else
		nbr_bytes = nmemb * size;
	ptr = malloc(nbr_bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nbr_bytes);
	return (ptr);
}
/*
#include <stdio.h>
int	main()
{	
	void  *ptr = ft_calloc(2, sizeof(int));
	free(ptr);
}
*/
