int max_subarray(int *arr, unsigned int n)
{
    int     sum;
    int     max;
    int     i;

    if (!n)
        return (0);

    max = 0;
    sum = 0;
    i = 0;
    while (i < n)
    {
        sum += arr[i];

        if (sum < arr[i])
            sum = arr[i];

        if (sum > max)
            max = sum;
        i++;
    }
    return (max);
}

#include <stdio.h>

int     main()
{
    int     arr[6] = {2, -8, 3, -2, 4, -10};

    printf("max = %d\n", max_subarray(arr, 6));

    return (0);
}