#include<bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define loop(i,a) for(int i=0;i<a;i++)
#define cont(i,a) for(int i=1;i<=a;i++)
#define circ(i,a,b) for(int i=a;i<=b;i++)
#define range(i,a,b,c) for(int i=a;c>0?i<=b:i>=b;i+=c)
#define parse(it,x) for(auto &it : x)
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
struct Edge{
	int to,cap,rev;
	Edge(int to,int cap,int rev): to(to),cap(cap),rev(rev){
	}
};
struct NetFlow{
	vector<Edge>egs[155];
	void inline init(){
		loop(i,155) egs[i].clear();
	}
	void inline addedge(int u,int v,int cap){
		egs[u].emb(v,cap,SZ(egs[v]));
		egs[v].emb(u,cap,SZ(egs[u])-1);
	}
	int dis[155];
	bool inline bfs(int s,int t){
		memset(dis,-1,sizeof(dis));
		dis[s]=0;
		queue<int>q;
		q.push(s);
		while(SZ(q)){
			int x=q.front();q.pop();
			parse(e,egs[x]){
				if(e.cap&&!~dis[e.to]){
					dis[e.to]=dis[x]+1;
					q.push(e.to);
				}
			}
		}
		return ~dis[t];
	}
	int iter[155];
	int inline dfs(int x,int t,int f){
		if(x==t) return f;
		for(int &i = iter[x];i<SZ(egs[x]);i++){
			Edge &e=egs[x][i];
			if(dis[e.to]==dis[x]+1&&e.cap){
				int fl=dfs(e.to,t,min(f,e.cap));
				if(fl){
					e.cap-=fl;
					egs[e.to][e.rev].cap+=fl;
					return fl;
				}
			}
		}
		return 0;
	}
	int inline getflow(int s,int t){
		int ans=0;
		while(bfs(s,t)){
			memset(iter,0,sizeof(iter));
			int tmp;
			while((tmp=dfs(s,t,Inf))) ans+=tmp;
		}
		return ans;
	}
}nf;
int n,m;
int u[3005],v[3005],w[3005];
int bel[155];
int ans[155][155];
void solve(){
	scanf("%d%d",&n,&m);
	cont(i,m) scanf("%d%d%d",u+i,v+i,w+i);
	int bls=0;
	memset(ans,Inf,sizeof(ans));
	memset(bel,0,sizeof(bel));
	cont(i,n) circ(j,i+1,n) if(bel[i]==bel[j]){
		nf.init();
		cont(j,m) nf.addedge(u[j],v[j],w[j]);
		int res=nf.getflow(i,j);
		cont(i,n) cont(j,n) if(bool(~nf.dis[i])^bool(~nf.dis[j])){
			ans[i][j]=min(ans[i][j],res);
		}
		++bls;
		cont(j,n) if(j!=i&&bel[j]==bel[i]&&~nf.dis[j]) bel[j]=bls;
		bel[i]=bls;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		int res=0;
		cont(i,n) circ(j,i+1,n) if(ans[i][j]<=x) ++res;
		printf("%d\n",res);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}

