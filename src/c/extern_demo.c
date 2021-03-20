#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline();
void copy();

#define MAXLINE 1000
/* maximum input line size */

char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */


int main()
{
    int len = 0; /* current line length */
    int max = 0;
    extern char longest[MAXLINE];
    while ((len = getline()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0)
        printf("Longest line [%s]\n", longest);
    return 0;
}

/* 
    getline: read a line into s, return length
*/
int getline(void)
{
    int c, i;
    extern char line[MAXLINE]; /* current input line */
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
