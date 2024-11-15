#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m,x,y,xx,yy,inf=1e9;
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
queue<pair<int,int>>q;
int d[N+5][N+5];
int main() {
	freopen("QUANMA.INP","r",stdin);
	freopen("QUANMA.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    	for (int j=1;j<=m;j++)
    		d[i][j]=inf;
    cin>>xx>>yy>>x>>y;
    q.push({xx,yy});
    d[xx][yy]=0;
    while (!q.empty()) {
    	int u=q.front().first;
    	int v=q.front().second;
    	q.pop();
    	for (int i=0;i<8;i++) {
    		int tx=u+dx[i],ty=v+dy[i];
    		if (tx>=1&&ty>=1&&tx<=n&&ty<=m&&d[tx][ty]==inf) {
    			q.push({tx,ty});
    			d[tx][ty]=d[u][v]+1;
    		}
    	}
    }
    if (d[x][y]!=inf) cout<<d[x][y];
    else cout<<-1;	
}

