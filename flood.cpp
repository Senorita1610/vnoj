#include<bits/stdc++.h>
using namespace std;
int n,m,head[400100],cnt,dir[100100][4],to[100100][4],x[100100],y[100100],S,mxy,dis[400100],tot;
bool vis[100100];
struct edge{
	int to,next,val;
}edge[1001000];
void ae(int u,int v,int w){
//	printf("%d %d %d\n",u,v,w);
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
int ori(int u,int v){
	if(y[u]==y[v])return x[u]>x[v];
	if(x[u]==x[v])return 2+(y[u]>y[v]);
}
void dye(int u){
	vis[u]=true;
	for(int i=0;i<4;i++){
		if(!dir[u][i])continue;
		if((i==0||i==2)&&y[u]>mxy)mxy=y[u],S=dir[u][i];
		if(!vis[to[u][i]])dye(to[u][i]);
	}
}
void bfs(){
	deque<int>q;
	q.push_back(S),dis[S]=0;
	while(!q.empty()){
		int u=q.front();q.pop_front();
//		printf("%d:%d\n",u,dis[u]);
		for(int i=head[u];i!=-1;i=edge[i].next){
			if(dis[edge[i].to]<=dis[u]+edge[i].val)continue;
//			printf("%d->%d:%d\n",u,edge[i].to,edge[i].val);
			dis[edge[i].to]=dis[u]+edge[i].val;
			if(edge[i].val)q.push_back(edge[i].to);
			else q.push_front(edge[i].to);
		}
	}
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head)),memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
//		printf("U,V:%d V,U:%d\n",ori(u,v),ori(v,u));
		dir[u][ori(u,v)]=i,to[u][ori(u,v)]=v;
		dir[v][ori(v,u)]=i,to[v][ori(v,u)]=u;
		ae(i,i+m,1);
	}
	for(int i=1;i<=n;i++){
		vector<int>v;
		if(dir[i][0])v.push_back(0);
		if(dir[i][2])v.push_back(2);
		if(dir[i][1])v.push_back(1);
		if(dir[i][3])v.push_back(3);
		if(v.empty())continue;
		int p,q;
		for(int j=0;j+1<v.size();j++){
			p=v[j],q=v[j+1],ae(dir[i][p]+(p==1||p==2)*m,dir[i][q]+(q==0||q==3)*m,0);
		}
		p=v.back(),q=v.front(),ae(dir[i][p]+(p==1||p==2)*m,dir[i][q]+(q==0||q==3)*m,0);
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		S=0,mxy=-1;
		dye(i);
		if(S)bfs();
	}
	for(int i=1;i<=m;i++)tot+=(dis[i]==dis[i+m]);
//	for(int i=1;i<=2*m;i++)printf("%d:%d\n",i,dis[i]);
	printf("%d\n",tot);
	for(int i=1;i<=m;i++)if(dis[i]==dis[i+m])printf("%d\n",i);
	return 0;
}

