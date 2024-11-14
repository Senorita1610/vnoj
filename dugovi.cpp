#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000+30, INF=2000000000+10;
int n, fa[MAXN], val[MAXN], ind[MAXN], now[MAXN];
void init() {
	scanf("%d", &n);
	for(int x=1; x<=n; ++x)
		scanf("%d%d", &fa[x], &val[x]), ++ind[fa[x]];
	return;
}
void solve() {
	int ans=0;
	for(int x=1; x<=n; ++x)
		if(ind[x]==0) {
			for(int u=x; ind[u]==0; u=fa[u]) {
				ans+=max(val[u]-now[u], 0);
				--ind[fa[u]];
				now[fa[u]]+=val[u];
				ind[u]=-1;
			}
		}
	for(int x=1; x<=n; ++x)
		if(ind[x]>0) {
			int dans=INF;
			for(int u=fa[x], su=x; ind[u]>0; su=u, u=fa[u]) {
				int c1=max(val[u]-val[su]-now[u], 0), c2=max(val[u]-now[u], 0);
				ans+=c1;
				if(dans>c2-c1) dans=c2-c1;
				ind[u]=0;
			}
			ans+=dans;
		}
	printf("%d\n", ans);
	return;
}
int main() {
	init();
	solve();
	return 0;
}

