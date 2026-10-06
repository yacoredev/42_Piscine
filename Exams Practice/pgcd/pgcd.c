int pgcd(unsigned int a, unsigned int b)
{
    unsigned int tmp;

    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return (a);
}