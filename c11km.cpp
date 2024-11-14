#include <bits/stdc++.h>
using namespace std;
int n,a[2000],f[2000][2000];
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			f[i][j]=99999999;
		}
	}
	f[0][0]=0;
	int ans=999999999;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j+1]);
			if(a[i]>100)
			{
				if(j>0)f[i][j]=min(f[i][j],f[i-1][j-1]+a[i]);
			}
			else 
			f[i][j]=min(f[i][j],f[i-1][j]+a[i]);
		}
	}
	for(int i=0;i<=n;i++)
	{
		ans=min(ans,f[n][i]);
	}
	cout << ans;
}

