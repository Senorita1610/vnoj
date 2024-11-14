#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 21
#define MAX 1000
typedef char string[MAXLEN];
int cmp(const void *a, const void *b)
{
    return strcmp(*(string*)a, *(string*)b);
}
int main()
{
    int n, k, nu = 0;
    string user[MAX];
    string s;
    for(scanf("%d\n", &k); k; k--)
    {
        for(scanf("%d\n", &n); n; n--)
        {
            gets(user[nu]);
            nu++;
        }
    }
    qsort(user, nu, sizeof(string), cmp);
    n = 1;
    for(k=1; k<nu; k++)
    {
        if(strcmp(user[k], user[k-1]))
                n++;
    }
    printf("%d\n", n);
    return 0;
}

