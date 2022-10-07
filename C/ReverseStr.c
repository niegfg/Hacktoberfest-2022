
#include <stdio.h>
#include <stdlib.h>
#define BUffer 50

/**
 * length - function that calculates length of a str
 * @str: str to reverse
 * Return: length of string in int
 */

int length(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    ;

    return (i);
}
/**
 * reverse - function to reverse a string
 * @str: string to reverse
 * Return:void
 */

void reverse(char *str)
{
    int x, y;
    char temp;

    x = length(str);
    for (y = 0; y < (x / 2); y++)
    {
        temp = str[x - y - 1];
        str[x - y - 1] = str[y];
        str[y] = temp;
    }
}

void main(void)
{
    int x,i;
    char strings[BUffer];
    char sample[] = "gnirtSedsreveR";
    
    printf("\n Sample of string reversed: gnirtSdesreveR\n");
    reverse(sample);
    printf("\nSample string: %s\n", sample);

    printf("\nenter the input string: \n");
    scanf("%s",strings);
    reverse(strings);
    printf("\nThe reversed string is: %s\n",strings);
}
