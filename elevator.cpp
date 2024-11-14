#include<bits/stdc++.h>
using namespace std;
int n;
struct node{	
	int h,a,c;
} a[11111111];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int f[11111111];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].h,&a[i].a,&a[i].c);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=a[i].c;k++)
		{
			for(int j=a[i].a;j>=a[i].h;j--)
			{
				f[j]=max(f[j],f[j-a[i].h]+a[i].h);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=a[n].a;i++)
	{
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}

