#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
#define maxn        1010
 
int     n , m , a[maxn][maxn];
int     h[maxn] , l[maxn] , r[maxn] , res;
 
int main()
{
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    h[0] = -1; h[n+1] = -1;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++)
            h[j] = a[i][j] * (h[j] + 1);
        for (int j=1;j<=n;j++) {
            l[j] = j;
            while (h[l[j]-1] >= h[j]) l[j] = l[l[j]-1];
        }
        for (int j=n;j>0;j--) {
            r[j] = j;
            while (h[r[j]+1] >= h[j]) r[j] = r[r[j]+1];
        }
        for (int j=1;j<=n;j++)
            res = max(res,h[j]*(r[j]-l[j]+1));
    }
    printf("%d",res);
}

