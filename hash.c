#include <stdio.h>
//In The Name Of God who is developing our lifes Algorithm
//Mohammadreza Sharifi
#include <string.h>

#include <time.h>
int charToInt(char c)
{
    int num = 0;
    num = c - '0';
    return num;
}////
/////////////////////////////////////////////////////////////
void reverse(char str[])
{
    int n = strlen(str);

    for (int i = 0; i < n / 2; i++)
    {
        char ch = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = ch;
    }
}
////////////////////////////////////////////////////////
char *hash(int a)
{
    int s = (clock() % 7) + 3;
    char origin[50], c[50], d[50], fina[50];
    int o, p, lota;
    o = (s * a * s);
    sprintf(origin, "%d", o);
    lota = strlen(origin);
    strcpy(d, origin);
    strcat(origin, d);
    reverse(origin);
    int k;
    char word;
    char fonat[50];
    k = strlen(origin);
    for (int i = 0; i < k; i++)
    {
        p = (rand() % 27) + 1;
        p += 55;
        word = p;
        fonat[i] = word;
    }
    for (int i = 0; i < k; i++)
    {
        fina[2 * i] = fonat[i];
        p=charToInt(origin[i]);
        fina[(2 * i) + 1] =65+p;
    }

    strcpy(d, fina);
    int t;

    sprintf(c, "%d", s);
    sprintf(origin, "%d", lota);
    strcat(c, origin);
    strcat(c, fina);
    char *sut;
    sut = c;
    return sut;
}
///////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
int dhash(char a[50])
{
    int j = 0;
    int b;
    b = 0;
    int k = charToInt(a[1]);
    int s = charToInt(a[0]);
    char w;
    int sal = 3;
    char final[10];
    for (int i = 0; i < k; i++)
    {
        w = ((a[sal + (2 * i)])%64)+47;
        final[k - i - 1] = w;
    }
    b = 0;
    for (int i = 0; i < k; i++)
    {
        j = charToInt(final[i]);
        b = (b * 10) + j;
    }
    b /= s * s;
    return b;
}
