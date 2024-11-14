#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,n1,tot,nd[N],cnt;
int x1[N],x2[N],y1[N],y2[N],bk[N],a[N],cp[N];
struct edge{
	int v,nxt;
}ed[N];
void add(int u,int v){
	ed[++tot]={v,nd[u]};
	nd[u]=tot;
}
int hung(int u){
	bk[u]=1;
	for(int i=nd[u];i;i=ed[i].nxt){
		int v=ed[i].v;
		if(bk[cp[v]])continue;
		if(cp[v]==0||hung(cp[v]))return cp[v]=u;
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		if(x1[i]>x2[i])swap(x1[i],x2[i]);
		if(y1[i]>y2[i])swap(y1[i],y2[i]);
		if(x1[i]==x2[i])a[i]=1,n1++;
		else a[i]=2;
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[i]==1&&a[j]==2)
				if(x1[i]>=x1[j]&&x2[i]<=x2[j]&&y1[j]>=y1[i]&&y2[j]<=y2[i])
					add(i,j+n1);
			if(a[i]==2&&a[j]==1)
				if(x1[j]>=x1[i]&&x2[j]<=x2[i]&&y1[i]>=y1[j]&&y2[i]<=y2[j])
					add(j,i+n1);
		}
	for(int i=1;i<=n;i++){
		if(a[i]==2)continue;
		memset(bk,0,sizeof(bk));
		if(hung(i))cnt++;
	}
	cout<<n-cnt<<endl;
	return 0;
}

