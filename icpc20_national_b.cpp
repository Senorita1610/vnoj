#include<bits/stdc++.h>
using namespace std;
const int N=1000100;
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
string g[N];
char temp[N];
int n,m,d[N];
pair<int,int>who[N];
inline bool valid(int x,int y){
	return x>=0 and y>=0 and x<n and y<m and g[x][y]!='@';
}
int main(){
	while(scanf("%d %d",&n,&m) and n and m){
		for(int i=0;i<n;i++){
			scanf("%s",temp);g[i]=temp;
			for(int j=0;j<m;j++) who[i*m+j]=make_pair(i,j);
		}
		for(int i=0;i<n*m;i++) d[i]=-1;
		deque<int>dq;
		for(int i=0;i<n;i++) if(g[i][0]!='@'){
			int u=i*m,w=g[i][0]=='.';
			if(d[u]!=-1) continue; d[u]=w;
			if(w) dq.emplace_back(u);
			else dq.emplace_front(u);
		}
		for(int i=0;i<m;i++) if(g[n-1][i]!='@'){
			int u=(n-1)*m+i,w=g[n-1][i]=='.';
			if(d[u]!=-1) continue; d[u]=w;
			if(w) dq.emplace_back(u);
			else dq.emplace_front(u);
		}
		int ans=-1;
		while(!dq.empty()){
			int u=dq.front();dq.pop_front();
			auto [x,y]=who[u];
			if(x==0 or y==m-1){
				ans=d[u];
				break;
			}
			for(int i=0;i<8;i++){
				int new_x=x+dx[i],new_y=y+dy[i];
				if(!valid(new_x,new_y)) continue;
				int v=new_x*m+new_y;
				if(~d[v]) continue;
				int w=g[new_x][new_y]=='.';
				d[v]=d[u]+w;
				if(w) dq.emplace_back(v);
				else dq.emplace_front(v);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

