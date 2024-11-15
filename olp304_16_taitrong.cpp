#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m,s,t,res;
vector<vector<pair<int,int>>>adj(N+5);
struct dat{
	int u,du;
	bool operator < (const dat &other) const {
		return du>other.du;
	}
};
priority_queue<dat>pq;
int d[N+5],inf=1e9;
bool check(int k) {
	for (int i=1;i<=n;i++) d[i]=inf;
	d[s]=0;
	pq.push({s,0});
	while (!pq.empty()) {
		int u=pq.top().u,du=pq.top().du;
		pq.pop();
		if (du!=d[u]) continue;
		for (auto [v,w]:adj[u]) {
			if (w<k) continue;
			if (d[v]>d[u]+w) {
				d[v]=d[u]+w;
				pq.push({v,d[v]});
			}
		}
	}
	return (d[t]!=inf);
}
int main() {
	freopen("TAITRONG.INP","r",stdin);
	freopen("TAITRONG.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    int lo=1,hi=1e4;
    while (lo<=hi) {
    	int mid=(lo+hi)/2;
    	if (check(mid)) {
    		res=mid;
    		lo=mid+1;
    	} else hi=mid-1;
    }
    cout<<res;
}

