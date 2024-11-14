#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int v,n,m;
int got[N],getjj[N],seat[N];
bool cmp(int i,int j){
	int wi=getjj[i]*(seat[j]+1),wj=getjj[j]*(seat[i]+1);
	return wi>wj || (wi==wj&&i<j);
}
void enumerate(){
	vector<int>cand;
	for(int i=0;i<n;i++){
		if(getjj[i]*100>=v*5){
			cand.push_back(i);
		}
	}
	if(cand.size()==0) return;
	for(int i=0;i<m;i++){
		int pos=-1;
		for(int j=0;j<(int)cand.size();j++){
			if(pos==-1||cmp(cand[j],pos)){
				pos=cand[j];
			}
		}
		++seat[pos];
	}
}
int largest(int u){
	int left=v;
	for(int i=0;i<n;i++){
		left-=got[i];
		getjj[i]=got[i];
	}
	getjj[u]+=left;
	memset(seat,0,sizeof(int)*n);
	enumerate();
	return seat[u];
}
bool byGot(int i,int j){
	return got[i]==got[j]?i<j:got[i]>got[j];
}
const int INF=1000000000;
int ord[N];
struct Frac{
	int a,b,id;
	Frac(int a,int b,int id): a(a),b(b),id(id){
	}
};
bool operator < (const Frac &a,const Frac &b){
	return a.a*b.b<b.a*a.b||(a.a*b.b==b.a*a.b&&a.id>b.id);
}
int delta(int v,int u){
	if(v<u){
		return (getjj[u]*(seat[v]+1)+seat[u])/(seat[u]+1)-getjj[v];
	}else{
		return (getjj[u]*(seat[v]+1)/(seat[u]+1)+1)-getjj[v];
	}
}
int getBak[N];
int cal(int n,int u,int left){
	int bak=left;
	for(int j=0;j<n;j++){
		getBak[ord[j]]=getjj[ord[j]];
	}
	for(int i=0;;i++){
		left=bak;
		seat[u]=i;
		Frac BAR = Frac(getjj[u],i+1,u);
		priority_queue<pair<int,int>>heap;
		int done=0;
		for(int j=0;j<n;j++){
			int v=ord[j];
			if(v==u){
				done+=i;
				continue;
			}
			for(int k=0;;k++){
				Frac cur=Frac(getjj[v],k+1,v);
				if(BAR<cur){
					++done;
				}else{
					seat[v]=k;
					heap.push(make_pair(-delta(v,u),v));
					break;
				}
			}
		}
		bool flag=true;
		for(int j=done;j<m&&flag;j++){
			if(heap.size()==0){
				flag=false;
				break;
			}
			int cost=-heap.top().first,id=heap.top().second;
			heap.pop();
			if(left<cost){
				flag=false;
				break;
			}
			left-=cost;
			getjj[id]+=cost;
			++seat[id];
			heap.push(make_pair(-delta(id,u),id));
		}
		for(int j=0;j<n;j++){
			getjj[ord[j]]=getBak[ord[j]];
		}
		if(flag) return i;
	}
}
int smallest(int u){
	if(n==1){
		return m;
	}
	if(got[u]*100<v*5){
		return 0;
	}
	int left=v;
	for(int i=0;i<n;i++){
		left-=got[i];
		getjj[i]=got[i];
		ord[i]=i;
	}
	sort(ord,ord+n,byGot);
	int ret=INF,st=0;
	while(st<n&&got[ord[st]]*100>=v*5){
		++st;
	}
	for(int i=st;i<=n;i++){
		ret=min(ret,cal(i,u,left));
		if(i<n){
			int u=ord[i],need=(v*5+99)/100;
			if(left<need-got[u]){
				break;
			}
			left-=need-got[u];
			getjj[u]=need;
		}
	}
	return ret;
}
int main(){
	scanf("%d%d%d",&v,&n,&m);
	for(int i=0;i<n;i++) scanf("%d",got+i);
	for(int i=0;i<n;i++){
		printf("%d%c",largest(i),i==n-1?'\n':' ');
	}
	for(int i=0;i<n;i++){
		printf("%d%c",smallest(i),i==n-1?'\n':' ');
	}
	return 0;
}

