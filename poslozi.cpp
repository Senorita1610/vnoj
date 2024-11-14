#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000001],dis[101][101],ans,sum=0,m,x,y;
vector<int>an;
struct dcz{
	int x,y;
}jh[100001];
int get(){
	int val=0;
	for(int i=1;i<=n;i++){
		val+=dis[i][a[i]];
	}
	return val;
}
void dfs(int st,int lst){
	int wssb=get();
	if(wssb==0){
		cout<<sum<<endl;
//		for(auto i:an){
//			cout<<i<<"\n";
//		}
		exit(0);
	}
	if(st+wssb/2+wssb%2>sum) return;
	for(int i=1;i<=m;i++){
		if(i==lst) continue;
		swap(a[jh[i].x],a[jh[i].y]);
		an.push_back(i);
		dfs(st+1,i);
		an.pop_back();
		swap(a[jh[i].x],a[jh[i].y]);
	}
}
signed main(){
	cin>>n>>m;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		jh[i].x=x,jh[i].y=y;
		dis[x][y]=dis[y][x]=min(1ll,dis[x][y]);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(1) dfs(0,-114514),sum++;
}

