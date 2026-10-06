#include <unistd.h>
#include <stdlib.h>

/*
	$> ./rotate_args 2 1 7 4 5
	4 5 1 7

	av[0] = ./a.out
	av[1] = 2
	av[2] = 1
	av[3] = 7
	av[4] = 4
	av[5] = 5

	k = 2
	n = 4 (3adad dyal values)
	k = 2 % 4 = 2

	print:

	av[4] av[5] av[2] av[3]
*/

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	if (ac > 1)
	{
		int len  = ac - 2;
		k = atoi(av[1]) % len;

		i = k + 2;
		while (i < ac)
		{
			j = 0;
			while(av[i][j])
			{
				write(1, &av[i][j++], 1);
				write(1, " ", 1);
			}
			i++;
		}
		i = 2;
		while (i < k + 2)
		{
			j = 0;
            while(av[i][j])
			{
				write(1, &av[i][j++], 1);
				write(1, " ", 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
