#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100000;
struct rd{
	int u,v,c;
	bool operator < (const rd& a) const{
		return c<a.c;
	}
}road[N+5];
int junc,rds;
int parent[N+5];
void takeInput(){
	scanf("%d%d",&junc,&rds);
	for(int i=0;i<=junc;i++){
		parent[i]=i;
	}
	for(int i=0;i<rds;i++){
		scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].c);
	}
}
int getParent(int x){
	return x==parent[x]?x:parent[x]=getParent(parent[x]);
}
int solve(){
	int pu,pv,total=0;
	sort(road,road+rds);
	for(int i=rds-1;i>=0;i--){
		pu=getParent(road[i].u);
		pv=getParent(road[i].v);
		if(pu!=pv){
			parent[pu]=pv;
		}else{
			total+=road[i].c;
		}
	}
	return total;
}
int main(){
	takeInput();
	cout<<solve()<<endl;
}

