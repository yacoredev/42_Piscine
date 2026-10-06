#include <unistd.h>
#include <stdlib.h>

/*

./a.out 1 2 3 1
0$
./a.out 1 2 3 7
1$
./a.out 42
1$

*/

// atoi malloc free
int     main(int ac, char **av)
{
    int *arr;
    int j;
    int i;

    if (ac > 1)
    {
        arr = malloc((ac - 1) * sizeof(int));
        if (!arr)
            return (0);
        j = 0;
        i = 1;
        while (av[i])
        {
         	arr[j] = atoi(av[i]);
		j++;
		i++;
        }
        i = 0;
        while (i < ac - 1)
        {
            j = i + 1;
            while (j < ac)
            {
                if (arr[i] == arr[j])
                {
                    write(1, "0\n", 2);
                    return (0);
                }
		        j++;
            }
            i++;
        }
	write(1, "1", 1);

    }
    write(1, "\n", 1);
    free(arr);
    return 0;
}
