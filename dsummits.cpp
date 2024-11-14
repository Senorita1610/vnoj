#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define maxn 505
#define ll long long
using namespace std;
int map[maxn][maxn];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vis[maxn][maxn];
struct node{
	int x,y,d;
	node(int x=0,int y=0,int d=0): x(x),y(y),d(d){
	}
	bool operator<(const node &t) const{
		return d>t.d;
	}
}arr[maxn*maxn];
queue<node>q;
int main(){
	int t,n,m,d;
		int cnt=0;
		scanf("%d%d%d",&n,&m,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&map[i][j]);
				arr[cnt++]=node(i,j,map[i][j]);
			}
		}
		memset(vis,-1,sizeof vis);
		int ans=0;
		sort(arr,arr+cnt);
		while(!q.empty()) q.pop();
		for(int i=0;i<cnt;i++){
			node v=arr[i];
			if(vis[v.x][v.y]!=-1) continue;
			bool flag=1;
			int bound=v.d-d;
			int peak=v.d;
			q.push(v);
			int cot=1;
			while(!q.empty()){
				node u=q.front();
				q.pop();
				vis[u.x][u.y]=peak;
				for(int i=0;i<4;i++){
					node tmp;
					tmp.x=u.x+dir[i][0];
					tmp.y=u.y+dir[i][1];
					if(tmp.x<1||tmp.x>n||tmp.y<1||tmp.y>m) continue;
					tmp.d=map[tmp.x][tmp.y];
					if(tmp.d<=bound) continue;
					if(vis[tmp.x][tmp.y]!=-1){
						if(vis[tmp.x][tmp.y]!=peak) flag=0;
						continue;
					}
					vis[tmp.x][tmp.y]=peak;
					if(tmp.d==peak) cot++;
					q.push(tmp);
				}
			}
			if(flag) ans+=cot;
		}
		printf("%d\n",ans);
	return 0;
}

