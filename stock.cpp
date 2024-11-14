#include<cstdio>
#include<cstring>
using namespace std;
int max(int x,int y) {return x>y?x:y;}
int t,n,m,maxx=-1,i,j,k,a[101][51],f[1000010];
int main()
{
	
	scanf("%d %d %d",&n,&t,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=t;j++)
			scanf("%d",&a[i][j]);
	for(k=2;k<=t;k++)
	{
		maxx=-1;
		for(i=1;i<=n;i++)
			for(j=a[i][k-1];j<=m;j++)
			{
				f[j]=max(f[j],f[j-a[i][k-1]]+a[i][k]-a[i][k-1]);
				maxx=max(f[j],maxx);
			}
		m+=maxx; memset(f,0,sizeof(f));
	}
	printf("%d",m);
	return 0;
}

