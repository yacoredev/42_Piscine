unsigned char swap_bits(unsigned char octet)
{
    // n7rk 4 bits lfo9 lta7t
    // w 4 bits lta7t lfou9
    // ba3d njm3hom
    return ((octet >> 4) | (octet << 4));
}