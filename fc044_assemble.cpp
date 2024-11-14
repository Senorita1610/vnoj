#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1000+6;
map<string,int>mp;
char name[50];
char fizz[50];
struct node{
	int mo;
	int q;
	node(int mo=0,int q=0): mo(mo),q(q){
	}
};
vector<node>v[maxn];
int id=0;
int ID(string name){
	if(!mp.count(name)){
		return mp[name]=id++;
	}
	return mp[name];
}
bool judge(int Q){
	int mon=m;
	for(int i=0;i<id;i++){
		int mi=0x3f3f3f3f;
		for(int j=0;j<v[i].size();j++){
			if(v[i][j].q>=Q){
				mi=min(mi,v[i][j].mo);
			}
		}
		if(mon<mi) return false;
		mon-=mi;
	}
	return true;
}
int main(){
		id=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%s%s%d%d",name,fizz,&x,&y);
			v[ID(name)].push_back(node(x,y));
		}
		int l=0,r=1e9;
		int m;
		while(l<=r){
			m=l+r>>1;
			if(judge(m)){
				l=m+1;
			}
			else r=m-1;
		}
		r=max(r,0);
		printf("%d\n",r);
}

