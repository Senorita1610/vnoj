#include<bits/stdc++.h>
#define mm(a,b) memset(a,b,sizeof(a))
#define ACCELERATE (ios::sync_with_stdio(false),cin.tie(0))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long,long long>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define rush() int T;scanf("%d,&T");while(T--)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d%d\n",a,b)
#define pf3(a,b,c) printf("%d%d%d\n",a,b,c)
#define debug(x) cout<<#x<<": "<<x<<endl
#define all(x) x.begin(),x.end()
#define PI acos(-1.0)
#define E exp(1.0)
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int ret=0,f=0;
	char c=gc();
	while(!isdigit(c)){
		if(c=='-') f=1;c=gc();
	}
	while(isdigit(c)){
		ret=ret*10+c-48;
		c=gc();
	}
	if(f) return -ret;
	return ret;
}
const int maxn=300+10;
ll g[maxn][maxn];
ll f[maxn];
ll dis[maxn];
bool vis[maxn];
ll stoer_wagner(int n){
	ll res=INF;
	rep(i,1,n) f[i]=i;
	while(n>2){
		int k,pre=1;
		mm(vis,0),mm(dis,0);
		vis[f[pre]]=1;
		rep(i,2,n){
			k=-1;
			rep(j,2,n){
				if(!vis[f[j]]){
					dis[f[j]]+=g[f[pre]][f[j]];
					if(k==-1||dis[f[k]]<dis[f[j]]) k=j;
				}
			}
			vis[f[k]]=true;
			if(i==n){
				res=min(res,dis[f[k]]);
				rep(j,1,n){
					g[f[pre]][f[j]]+=g[f[j]][f[k]];
					g[f[j]][f[pre]]+=g[f[j]][f[k]];
				}
				f[k]=f[n--];
			}
			pre=k;
		}
	}
	return res;
}
int main(){
	int n,m,s;
	while(1){
		n=read();m=read();s=read();
		if(!(n||m||s)) break;
		rep(i,1,n) rep(j,1,n) g[i][j]=0;
		rep(i,1,m){
			int u,v,w;
			u=read();
			v=read();
			w=read();
			if(u==s&&v!=1){
				g[1][v]+=w;
				g[v][1]+=w;
			}
			else if(v==s&&u!=1){
				g[u][1]+=w;
				g[1][u]+=w;
			}
			else if(u==s&&v==1){
				g[u][v]+=w;
				g[v][u]+=w;
			}
			else if(v==s&&u==1){
				g[u][v]+=w;
				g[v][u]+=w;
			}
			else if(u!=s&&v==1){
				g[u][s]+=w;
				g[s][u]+=w;
			}
			else if(v!=s&&u==1){
				g[v][s]+=w;
				g[s][v]+=w;
			}
			else{
				g[u][v]+=w;
				g[v][u]+=w;
			}
		}
		if(n==1) puts("0");
		else if(n==2) printf("%lld\n",g[1][2]);
		else printf("%lld\n",stoer_wagner(n));
	}
	return 0;
}

