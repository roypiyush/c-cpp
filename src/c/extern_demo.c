#include <stdio.h>
#define MAXLINE 1000

int getlineFunc();
void copy();

#define MAXLINE 1000

char line[MAXLINE];
char longest[MAXLINE];


int main()
{
    int len = 0;
    int max = 0;
    extern char longest[MAXLINE];
    while ((len = getlineFunc()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0)
        printf("Longest line [%s]\n", longest);
    return 0;
}

int getlineFunc(void)
{
    int c, i;
    extern char line[MAXLINE];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = '\0';
        ++i;
    }
    return i;
}

void copy(void)
{
    int i;
    extern char line[MAXLINE];
    extern char longest[MAXLINE];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
