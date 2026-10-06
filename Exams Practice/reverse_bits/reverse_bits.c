unsigned char reverse_bits(unsigned char octet)
{
    unsigned char result;
    int i;

    // nbda b byte khawi
    result = 0;

    // 3andna 8 bits
    i = 8;

    while (i--)
    {
        // n7ell result bit l lisar
        result <<= 1;

        // nakhod akher bit mn octet
        // w nzido l result
        result |= (octet & 1);

        // n7yed dak bit mn octet
        octet >>= 1;
    }

    return (result);
}