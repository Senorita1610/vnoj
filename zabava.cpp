#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,m,k,i,j,x,kk,kkk,num,sum,mon,a[555],f[555][555];

int cmf(int i, int j, int kk)
{
        kkk=j-kk;
        mon=a[i] / (kkk+1);
        sum=(mon+1) * (kkk+1) - a[i];
        num=(kkk+1) - sum;
        sum=sum * mon * (mon+1) / 2 + num * (mon+1) * (mon+2) / 2;
        return sum;
}

signed main()
{
        cin >> n >> m >> k;
        for (i=1; i<=n; i++)
        {
                cin >> x;
                a[x]++;
        }

        for (i=1; i<=m; i++)
                for (j=0; j<=k; j++)
                        f[i][j]=0x3f3f3f3f;

        for (i=1; i<=m; i++)
                for (j=0; j<=k; j++)
                        for (kk=0; kk<=j; kk++)
                                f[i][j]=min(f[i][j],f[i-1][kk]+cmf(i,j,kk));
        cout << f[m][k];
}

