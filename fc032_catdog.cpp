#include<iostream>
#include<cstring>
#include<cstdio>
struct Hungary{
	static const int N=506,E=260006;
	struct ARC{
		int u,next;
		void init(int _u,int _next){
			u=_u,next=_next;
		}
	}arc[E];
	int head[N],n,m,mth_L[N],mth_R[N];
	bool vs[N];
	void init(int _n){
		n=_n,m=0;
		memset(head,-1,sizeof head);
	}
	void add_arc(int s,int t){
		arc[m].init(t,head[s]);
		head[s]=m++;
	}
	bool Find(int u){
		if(vs[u]) return false;
		vs[u]=true;
		for(int e=head[u];e!=-1;e=arc[e].next){
			int v=arc[e].u;
			if(mth_R[v]==-1||Find(mth_R[v])){
				mth_L[u]=v,mth_R[v]=u;
				return true;
			}
		}
		return false;
	}
	int MaxMatch(){
		int ans=0;
		memset(mth_L,-1,sizeof mth_L);
		memset(mth_R,-1,sizeof mth_R);
		for(bool flag=false;1;flag=false){
			memset(vs,0,sizeof vs);
			for(int i=0;i<n;i++){
				if(mth_L[i]==-1&&Find(i)) ans++,flag=true;
			}
			if(!flag) return ans;
		}
	}
};
struct Peo{
	char like[10],dislike[10];
}A[506];
Hungary fuck;
bool g[506][506];
int n1,n2,n;
int main(){
	while(scanf("%d%d%d",&n1,&n2,&n)!=EOF){
		memset(g,0,sizeof g);
		for(int i=0;i<n;i++){
			scanf("%s%s",A[i].like,A[i].dislike);
		}
		fuck.init(n);
		for(int i=0;i<n;i++){
			if(A[i].like[0]!='C') continue;
			for(int j=0;j<n;j++){
				if(A[j].like[0]!='D') continue;
				if(strcmp(A[i].like,A[j].dislike)==0||strcmp(A[i].dislike,A[j].like)==0) fuck.add_arc(i,j);
			}
		}
		printf("%d\n",n-fuck.MaxMatch());
	}
	return 0;
}

