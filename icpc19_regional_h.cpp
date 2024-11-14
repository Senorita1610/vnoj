#include<cstdio>
#include<vector>
using namespace std;
vector<int>h[10];
int r,c,ans,ks,hk[10],hz[10];
vector<int>zk[10];
void dfs(int x,int y,int k,int z){
	if(y==c+1){
		if(k==ks){
			h[x].push_back(z);
		}
		return;
	}
	dfs(x,y+1,k,z);
	if(k==ks||y+hk[k]-1>c) return;
	for(int i=1;i<=hk[k];++i,++y)
		z+=1<<(y-1);
	if(y<=c) ++y;
	dfs(x,y,k+1,z);
}
bool pd(){
	for(int j=1;j<=c;j++){
		int k=0,l=0;
		for(int i=1;i<=r+1;i++){
			if(hz[i]>>(j-1)&1&&i!=r+1) ++l;
			else if(l){
				if(k==(int)zk[j].size()||zk[j][k]!=l) return 0;
				l=0,++k;
			}
		}
	}
	return 1;
}
void mj(int x){
	if(x==r+1){
		if(pd()) ++ans;
		return;
	}
	for(auto i:h[x]){
		hz[x]=i;
		mj(x+1);
	}
}
int main(){
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++){
		scanf("%d",&ks);
		for(int j=0;j<ks;j++){
			scanf("%d",&hk[j]);
		}
		dfs(i,1,0,0);
	}
	for(int i=1;i<=c;i++){
		scanf("%d",&ks);
		for(int j=1;j<=ks;j++){
			int a;
			scanf("%d",&a);
			zk[i].push_back(a);
		}
	}
	mj(1);
	printf("%d",ans);
	return 0;
}

