#include <unistd.h>

void    print_bits(unsigned char octet)
{
    int i;

    // nbda mn bit l'akher (bit 7)
    i = 7;

    while (i >= 0)
    {
        // nkhlli bit li bghina howa l'awal
        // b shift l ymin
        if ((octet >> i) & 1)
            write(1, "1", 1); // ila kan bit = 1
        else
            write(1, "0", 1); // ila kan bit = 0

        // nmchi l bit li mn ba3do
        i--;
    }
}

/*
    octet = 13

    13 = 00001101

    i = 7
    00001101 >> 7 = 00000000
    &1 = 0

    i = 3
    00001101 >> 3 = 00000001
    &1 = 1

    ...
*/