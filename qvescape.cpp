#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Rep(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
inline long long read()
{
	char c=getchar();long long x=0;bool f=0;
	while(!isdigit(c))f^=!(c^45),c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f)x=-x;return x;
}
const int maxn=100010;
const int maxm=200010;
struct edge{int next,v;long long w;}e[3*maxm];
map<long long,int>MP;
int head[maxm],cnt;
long long n,dis[maxm],d,w;
int m,u,v,s,pos;
long long a[maxn],b[maxn];
long long p[maxm];
struct node
{
	int u;
	long long d;
	bool operator <(const node& r) const{return d>r.d;}
};
node Q;
void add(int u,int v,long long w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
priority_queue<node>q;
long long g,h,j,k;
long long finda(long long g)
{
	k=sqrt(g);
	if(k%2==1) k--;
	if(g==4) return 1;
	if(g==k*k) return (k-2)*(k-2)+1;
	h=(g-k*k)/(k+1);
	h*=2;
	j=(k-2)*(k-2)+(g-k*k-1)-h;
	return j;
}
int main()
{
	memset(dis,0x3f,sizeof dis);
	n=read();scanf("%d",&m);
	MP[1]=1;p[++pos]=1;
	MP[n]=1;p[++pos]=n;
	For(i,1,m)
	{
		a[i]=read();b[i]=finda(a[i]);
		if(!MP[a[i]])
		{
			MP[a[i]]=1;
			p[++pos]=a[i];
		}
		if(!MP[b[i]])
		{
			MP[b[i]]=1;
			p[++pos]=b[i];
		}
	}
	sort(p+1,p+pos+1);
	For(i,1,pos)
	{
		MP[p[i]]=i;
	}
	For(i,1,pos-1)
	{
		add(i,i+1,p[i+1]-p[i]);
		add(i+1,i,p[i+1]-p[i]);
	}
	For(i,1,m)
	{
		add(MP[a[i]],MP[b[i]],1ll);
		add(MP[b[i]],MP[a[i]],1ll);
	}
	dis[1]=0;
	q.push((node){1,0});
	while(!q.empty())
	{
		Q=q.top();
		q.pop();
		u=Q.u;d=Q.d;
		if(d!=dis[u])
			continue;
		for(int i=head[u];i;i=e[i].next)
		{
			v=e[i].v;w=e[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push((node){v,dis[v]});
			}
		}
	}
	printf("%lld",dis[MP[n]]);
}

