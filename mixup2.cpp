#include<bits/stdc++.h>
using namespace std;
long long n,sb,a[17],f[17][65536],ans;
int main()
{
	scanf("%lld%lld",&n,&sb);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)f[i][1<<(i-1)]=1;
	for(long long j=1;j<=(1<<n)-1;j++)
	{
		for(long long i=1;i<=n;i++)
		{
			if(!(j&(1<<i-1)))continue;
			for(long long k=1;k<=n;k++)
			{
				if(j&(1<<(k-1)))continue;
				if(abs(a[k]-a[i])>sb)f[k][(1<<(k-1))|j]+=f[i][j];
			}
		}
	}
	for(long long i=1;i<=n;i++)ans+=f[i][(1<<n)-1];
	printf("%lld",ans);
}

