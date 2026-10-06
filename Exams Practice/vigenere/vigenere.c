#include <unistd.h>

int is_alpha(char c)
{
    return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int is_lower(char c)
{
   return (c >= 'a' && c <= 'z');
}

int ft_move(char key)
{
    int sheft;

    if (key >= 'a' && key <= 'z')
        sheft = key - 'a';
    else
        sheft = key - 'A';
    return (sheft);
}

int main(int ac, char **av)
{
    char    *str;
    char    *key;
    char    c;
    int     move;
    int     i;
    int     j;

    if (ac == 3)
    {
        key = av[2];
        str = av[1];
        j = 0;
        i = 0;
        while (str[i])
        {
            if (is_alpha(str[i]))
            {
                move = ft_move(key[i]);
                if (is_lower(str[i]))
                    c = (((str[i] - 'a') + move) % 26) + 'a';

                else
                    c = (((str[i] - 'A') + move) % 26) + 'A';

                write(1, &c, 1);
                if (key[++j] == '\0')
                    j = 0;
            }
            else
                write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}