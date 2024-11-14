#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=55;
int vis[maxn];
int y[maxn];
vector<int>G[maxn];
int n,m;
char a[maxn][maxn];
bool dfs(int u){
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(vis[v]) continue;
		vis[v]=true;
		if(y[v]==-1||dfs(y[v])){
			y[v]=u;
			return true;
		}
	}
	return false;
}
int match(){
	int ans=0;
	memset(y,-1,sizeof(y));
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans;
}
int main(){
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%s",a[i]);
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='1'){
					int sum1=0,sum2=0;
					for(int h=0;h<m;h++){
						if(a[i][h]=='1'){
							sum1++;
						}
					}
					for(int h=0;h<n;h++){
						if(a[h][j]=='1'){
							sum2++;
						}
					}
					if(ans>=sum1+sum2) continue;
					for(int h=0;h<n;h++){
						G[h].clear();
						if(a[h][j]=='1'){
							for(int k=0;k<m;k++){
								if(a[i][k]=='1'&&a[h][k]=='0'){
									G[h].push_back(k);
								}
							}
						}
					}
					int res=match();
					if(sum1+sum2-res>ans){
						ans=sum1+sum2-res;
					}
				}
			}
		}
		printf("Case %d: %d\n",cas++,ans);
	}
	return 0;
}

