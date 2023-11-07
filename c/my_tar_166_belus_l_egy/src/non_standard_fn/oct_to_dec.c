#include "../../include/main_header.h"

int oct_to_dec(int value)
{
    int dec = 0;
    int base = 1;
    int temp = value;

    while (temp)
    {
        int lastdigit = temp % 10;
        temp = temp / 10;

        dec += lastdigit * base;

        base = base * 8;
    }

return dec;
}