#include <bits/stdc++.h>
using namespace std;
string s;
int kt[1002][1002],f[1002],n;
int main()
{
    cin>>s;
    n=s.length();
    s='-'+s;
    for (int i=1;i<=n;++i) kt[i][i]=1;
    for (int i=n-1;i>=1;--i)
        for (int j=i+1;j<=n;++j)
            if ((s[i]==s[j])&&(j-i==1 || kt[i+1][j-1]==1)) kt[i][j]=1;
            else kt[i][j]=0;
    f[1]=1;
    for (int i=2;i<=n;++i)
    {
        f[i]=f[i-1]+1;
        for (int k=2;k<=i;++k)
            if (kt[i-k+1][i]==1) f[i]=min(f[i],f[i-k]+1);
    }
    cout<<f[n];
}

