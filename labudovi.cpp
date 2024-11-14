#include<bits/stdc++.h>
using namespace std;
const int N=1500;
int r,c;
char a[N+5][N+5];
int d[N+5][N+5];
bool vis[N+5][N+5];
pair<int,int>p1,p2;
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
void bfs() {
	queue<pair<int,int>>q;
	for (int i=1;i<=r;i++) 
		for (int j=1;j<=c;j++)
			if (a[i][j]!='X') q.push({i,j});
			else d[i][j]=-1;
	while (!q.empty()) {
		pair<int,int>t=q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int x=t.first+dx[i],y=t.second+dy[i];
			if (x>=1&&y>=1&&x<=r&&y<=c&&d[x][y]==-1) {
				q.push({x,y});
				d[x][y]=d[t.first][t.second]+1;
			}
		}
	}  
}
bool check(int k) {
	queue<pair<int,int>>q;
	q.push(p1);
	memset(vis,false,sizeof(vis));
	vis[p1.first][p1.second]=true;
	while (!q.empty()) {
		pair<int,int>t=q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int x=t.first+dx[i],y=t.second+dy[i];
			if (x>=1&&y>=1&&x<=r&&y<=c&&d[x][y]<=k&&!vis[x][y]) {
				if (x==p2.first&&y==p2.second) return true;
				q.push({x,y});
				vis[x][y]=true;
			}
		}
	}  
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>r>>c;
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			cin>>a[i][j];
			if (a[i][j]=='L') {
				if (p1.first==0) p1={i,j};
				else p2={i,j};
			}
		}
	}
	bfs();
	int lo=0,hi=max(r,c),res=0;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(mid)) {
			hi=mid-1;
			res=mid;
		} else lo=mid+1;
	}
	cout<<res;
}

