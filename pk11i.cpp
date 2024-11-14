#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x,y) memset(x,y,sizeof(x))
const LL INF=1e9+7;
const int N=2e4+10;
vector<pair<int,int>>v[N];
int ans=0;
int dfs(int x,int fa=-1){
	int sum0=0,sum1=0;
	for(auto& [y,o]: v[x]){
		if(y==fa) continue;
		int ret=dfs(y,x);
		if(ret*o<=0){
			ans+=abs(ret);
			ret=o;
		}
		if(ret>0) sum0+=ret;
		else sum1+=ret;
	}
	ans+=min(abs(sum0),abs(sum1));
	return sum0+sum1;
}
int main(){
	int ncase;
	scanf("%d",&ncase);
	int ks=1;
	while(ncase--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].emplace_back(y,1);
			v[y].emplace_back(x,-1);
		}
		ans=0;
		ans+=abs(dfs(0));
		printf("Case %d: %d\n",ks++,ans);
	}
	return 0;
}

