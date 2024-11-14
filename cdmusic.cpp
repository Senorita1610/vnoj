#include<bits/stdc++.h>
#define int long long
#define MAXN 1145141919180
using namespace std;

const int M=300010;
int n,k,m,Minn=MAXN;
int b[M]={MAXN},minn=MAXN,maxn;
int dp[M];
// dp[i] ? i ???? 
//dp[i]=min(dp[j]+a[i]-a[j+1]+1)
//a[i]-a[j+1]+1>=k
//a[j+1]<=a[i]+1-k

int l[M],r[M];

struct node
{
	int a,id;
}a[M];

bool cmp(node a,node b)
{
	return a.a<b.a;
}

inline int read()
{
	int f=1,num=0;char ch=getchar();
	while(!((ch<='9'&&ch>='0')||ch=='-'))ch=getchar();
	if (ch=='-')f=-1;else num=ch-'0';
	while(ch=getchar(),ch<='9'&&ch>='0')num=num*10+ch-'0';
	return num*f;
}

int min(int a,int b){return a>b?b:a;}

signed main()
{
	n=read(),k=read(),m=read();
	for (int i=1;i<=m;i++)a[i].a=read(),a[i].id=i,Minn=min(Minn,a[i].a);
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m;i++)
	{
		if (a[i].a-a[1].a+1<=k)dp[i]=k;
		else dp[i]=a[i].a-a[1].a+1;
		int tl=1,tr=m,p=0;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (a[i].a-a[Mid].a+1>=k)tl=Mid+1,p=Mid;
			else tr=Mid-1;
		}
		if (p!=0)dp[i]=min(dp[i],b[p-1]+a[i].a+1);
		dp[i]=min(dp[i],dp[p]+k);
		b[i]=min(b[i-1],dp[i]-a[i+1].a);;
		if(dp[i]-dp[i-1]>a[i].a-a[i-1].a)
		{
			l[a[i].id]=a[i].a;
			r[a[i].id]=a[i].a+k-1;
		}
		else
		{
			r[a[i].id]=a[i].a;
			l[a[i].id]=a[i].a-k+1;
		}
	}
	for (int i=1;i<=m;i++)if (l[i]<Minn)r[i]+=Minn-l[i],l[i]+=Minn-l[i];
	for (int i=1;i<=m;i++)if (r[i]>n)l[i]+=n-r[i],r[i]+=n-r[i];
	cout<<dp[m]<<endl;
	return 0;
}

