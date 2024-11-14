#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
#define LL long long
#define MP make_pair
#define mod 1000000007
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define mxn 100
#define mxe 20000
const int INF=2100000000;
int dis[mxn],pre[mxn],gap[mxn],arc[mxn],f[mxe],cap[mxe];
int first[mxn],nxt[mxe],vv[mxe],e;
inline void add(int u,int v,int c){
	vv[e]=v,cap[e]=c,nxt[e]=first[u],first[u]=e++;
	vv[e]=u,cap[e]=0,nxt[e]=first[v],first[v]=e++;
}
int sap(int s,int t,int n){
	int q[mxn],j,mindis,ans=0,head=0,tail=1,u,v,low;
	bool found, vis[mxn];
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	memset(vis,0,sizeof(vis));
	memset(arc,-1,sizeof(arc));
	memset(f,0,sizeof(f));
	q[0]=t;
	vis[t]=true;
	dis[t]=0;
	gap[0]=1;
	while(head<tail){
		u=q[head++];
		for(int i=first[u];i!=-1;i=nxt[i]){
			v=vv[i];
			if(!vis[v]){
				dis[v]=dis[u]+1;
				vis[v]=true;
				q[tail++]=v;
				gap[dis[v]]++;
				arc[v]=first[v];
			}
		}
	}
	u=s;low=INF;pre[s]=s;
	while(dis[s]<n){
		found=false;
		for(int &i=arc[u];i!=-1;i=nxt[i]){
			if(dis[vv[i]]==dis[u]-1&&cap[i]>f[i]){
				found=true;
				v=vv[i];
				low=low<cap[i]-f[i]?low:cap[i]-f[i];
				pre[v]=u;
				u=v;
				if(u==t){
					while(u!=s){
						u=pre[u];
						f[arc[u]]+=low;
						f[arc[u]^1]-=low;
					}
					ans+=low;
					low=INF;
				}
				break;
			}
		}
		if(found) continue;
		mindis=n;
		for(int i=first[u];i!=-1;i=nxt[i]){
			if(mindis>dis[vv[i]]&&cap[i]>f[i]){
				mindis=dis[vv[j=i]];
				arc[u]=i;
			}
		}
		gap[dis[u]]--;
		if(gap[dis[u]]==0){
			return ans;
		}
		dis[u]=mindis+1;
		gap[dis[u]]++;
		u=pre[u];
	}
	return ans;
}
char s[45][45];
int r[45],c[45];
int cal(int x,int y,int n,int m){
	memset(first,-1,sizeof(first));
	e=0;
	int S=n+m+1,T=S+1,R=0,C=0;
	REP(i,1,n) add(S,i,abs(r[i]-x)),R+=abs(r[i]-x);
	REP(j,1,m) add(j+n,T,abs(c[j]-y)),C+=abs(c[j]-y);
	REP(i,1,n) REP(j,1,m){
		bool ok=false;
		if(r[i]<x&&c[j]<y&&s[i][j]=='0') ok=true;
		if(r[i]>x&&c[j]>y&&s[i][j]=='1') ok=true;
		if(ok) add(i,j+n,1);
	}
	int M=sap(S,T,T);
	int ret=R+C-M+min(R-M,C-M);
	return ret;
}
int solve(int n,int m){
	int ret=INF;
	REP(i,0,m) if(i*n%m==0) ret=min(ret,cal(i,i*n/m,n,m));
	return ret;
}
int main(){
	int n,m,t,cas=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		REP(i,1,n) scanf("%s",s[i]+1);
		REP(i,1,n) REP(j,1,m) if(s[i][j]=='1') ++r[i],++c[j];
		printf("Case %d: %d\n",++cas,solve(n,m));
	}
	return 0;
}

