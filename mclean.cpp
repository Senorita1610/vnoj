#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define LL long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
using namespace std;
const int N=21;
const int mod=1e9+7;
int n,m,k,st;
char s[N][N];
pair<int,int>a[N];
pair<int,int>q[N*N];
int ql,qr;
int u[N][N],d[N][N],dist[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool can(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='x';
}
void bfs(int id){
	int x=a[id].f,y=a[id].s;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			u[i][j]=0,d[i][j]=-1;
		}
	}
	u[x][y]=1;
	d[x][y]=0;
	ql=qr=0;
	q[qr++]=mp(x,y);
	while(ql<qr){
		pii v=q[ql++];
		for(int i=0,tox,toy;i<4;i++){
			tox=dx[i]+v.f,toy=dy[i]+v.s;
			if(can(tox,toy)&&!u[tox][toy]){
				u[tox][toy]=1;
				d[tox][toy]=d[v.f][v.s]+1;
				q[qr++]=mp(tox,toy);
			}
		}
	}
	for(int i=0;i<k;i++) dist[id][i]=d[a[i].f][a[i].s];
}
bool calced[1<<12][12];
int dp[1<<12][12];
int calc(int mask,int v){
	if(mask==(1<<k)-1) return 0;
	if(calced[mask][v]) return dp[mask][v];
	calced[mask][v]=1;
	int res=INT_MAX/2;
	for(int i=0;i<k;i++){
		if(mask&(1<<i)) continue;
		if(dist[v][i]!=-1){
			res=min(res,calc(mask|(1<<i),i)+dist[v][i]);
		}
	}
	return dp[mask][v]=res;
}
void solve(){
	scanf("%d%d",&m,&n);
	if(m+n==0) exit(0);
	k=0;
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<m;j++){
			if(s[i][j]=='*') a[k++]=mp(i,j);
			if(s[i][j]=='o') st=k,a[k++]=mp(i,j);
		}
	}
	for(int i=0;i<k;i++) bfs(i);
	int ans=calc(1<<st,st);
	if(ans>=INT_MAX/2) ans=-1;
	printf("%d\n",ans);
	memset(calced,0,sizeof calced);
}
int main(){
	while(1) solve();
	return 0;
}

