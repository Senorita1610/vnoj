#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a[10000],l,f[10000];
	cin >> n >> l;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
	cin >> a[i];
	a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=1000000000;
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]-a[j]>l) break;
			f[i]=min(f[i],max(f[j],l-(a[i]-a[j])));
		}
	}
	cout << f[n];
}

