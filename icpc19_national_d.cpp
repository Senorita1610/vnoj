#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=2e18;
const int N=55;
int R,C,K;
char s[N][N];
ll a[N];
int vis[N][N];
void dfs(int x,int y){
	if(x<0||x>=R||y<0||y>=C||s[x][y]=='X'||vis[x][y]) return;
	vis[x][y]=1;
	if(s[x][y]=='L'||s[x][y]=='?') dfs(x,y-1);
	if(s[x][y]=='R'||s[x][y]=='?') dfs(x,y+1);
	if(s[x][y]=='.') dfs(x+1,y);
}
#define vll vector<ll>
#define mat vector<vll>
mat mul(mat a,mat b){
	mat ans(C,vll(C,0));
	for(int i=0;i<C;i++){
		for(int k=0;k<C;k++){
			for(int j=0;j<C;j++){
				ans[i][j]=max(ans[i][j],a[i][k]+b[k][j]);
			}
		}
	}
	return ans;
}
mat pow(mat a,int k){
	mat ans=a;
	--k;
	while(k){
		if(k&1) ans=mul(ans,a);
		a=mul(a,a);
		k>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&R,&C,&K);
	for(int i=0;i<R;i++) scanf("%s",s[i]);
	for(int i=0;i<C;i++){
		scanf("%lld",&a[i]);
	}
	mat cost(C,vll(C,0));
	for(int i=0;i<C;i++){
		for(int j=0;j<C;j++){
			cost[i][j]=-inf;
		}
	}
	for(int i=0;i<C;i++){
		memset(vis,0,sizeof(vis));
		dfs(0,i);
		for(int j=0;j<C;j++) if(vis[R-1][j]&&s[R-1][j]=='.')
			cost[i][j]=a[j];
	}
	mat ans=pow(cost,K);
	ll res=0;
	for(int i=0;i<C;i++) for(int j=0;j<C;j++) res=max(res,ans[i][j]);
	cout<<res<<endl;
	return 0;
}

