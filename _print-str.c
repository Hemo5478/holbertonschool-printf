#include "main.h"

void _print_str(const char* str)
{
    while (*str)
    {
        putchar(*str);
        str++;
    }
}
