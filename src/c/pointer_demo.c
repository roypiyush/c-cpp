#include <stdio.h>

int main(int argc, char *argv[])
{

    char hello[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};

    char *c = hello;
    printf("refer char[] using pointer -> %s\n", c);

    for (size_t i = 0; i < 20; i++)
    {
        printf("%s\r", c - i);
    }

    for (size_t i = 0; i < 20; i++)
    {
        printf("%s\r", c + i);
    }

    printf("%s\n", c + 1);

    int *ip;
    int x = 5;
    ip = &x;
    *ip = *ip + 1;
    printf("int value = %d | Int pointer Value = %d  address = %p\n", x, *ip, ip);
}