#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int count;

    count = 0;
    while (begin_list)
    {
        count++;
        begin_list = begin_list->next;
    }
    return (count);
}

#include <stdio.h>
int main()
{
    t_list n1;
    t_list n2;
    t_list n3;
    
    n1.next = &n2;
    n2.next = &n3;
    n3.next = 0;

    printf("count = %d\n", ft_list_size(&n1));
}