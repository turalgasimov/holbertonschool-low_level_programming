#include "main.h";

/**
 * puts2 - puts even
 * @str: ptr to str
 * Return: void
 */

void puts2(char *str)
{
        while (*str != '\0')
        {
                _putchar(*str);
                str += 2;
        }
}
