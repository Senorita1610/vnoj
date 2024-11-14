#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int test,n,m,k,x,y,bian,s,t,ans,z,head[2001],f[2001],liu[10001],to[10001],a[2001],from[10001],pr[2001],len[2001],cost[10001],nex[10001];
bool vis[2001];
queue<int>q;
void add(int x,int y,int z,int w){
	nex[bian]=head[x];
	to[bian]=y;
	from[bian]=x;
	liu[bian]=z;
	cost[bian]=w;
	head[x]=bian++;
	nex[bian]=head[y];
	to[bian]=x;
	from[bian]=y;
	liu[bian]=0;
	cost[bian]=-w;
	head[y]=bian++;
}
bool spfa(){
	memset(len,0x3f,sizeof len);
	memset(vis,0,sizeof vis);
	len[s]=0;
	f[s]=0x3f3f3f3f;
	vis[s]=true;
	q.push(s);
	while(!q.empty()){
		k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=head[k];i!=-1;i=nex[i]){
			if((len[to[i]]>len[k]+cost[i])&&(liu[i])){
				len[to[i]]=len[k]+cost[i];
				f[to[i]]=min(f[k],liu[i]);
				pr[to[i]]=i;
				if(!vis[to[i]]){
					vis[to[i]]=true;
					q.push(to[i]);
				}
			}
		}
	}
	return len[t]<0x3f3f3f3f;
}
int fei(){
	ans=0;
	while(spfa()){
		ans+=len[t]*f[t];
		for(int i=t;i!=s;i=from[pr[i]]){
			liu[pr[i]]-=f[t];
			liu[pr[i]^1]+=f[t];
		}
	}
	return ans;
}
int main(){
	scanf("%d",&test);
	for(int ii=1;ii<=test;ii++){
		scanf("%d",&n);
		bian=s=0;
		memset(head,-1,sizeof head);
		t=n+1;
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			if(k>1) add(s,i,k-1,0);
			if(!k) add(i,t,1,0);
		}
		for(int i=1;i<n;i++) add(i,i+1,0x3f3f3f3f,1);
		add(n,1,0x3f3f3f3f,1);
		for(int i=2;i<=n;i++) add(i,i-1,0x3f3f3f3f,1);
		add(1,n,0x3f3f3f3f,1);
		printf("%d\n",fei());
	}
}

