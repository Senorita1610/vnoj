#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e9+7;
int n,m,c,L;
char s[55];
inline int ADD(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
struct Matrix{
	int a[1<<8|5][1<<8|5];
	void clear(){
		memset(a,0,sizeof a);
	}
	void set(){
		clear();
		for(int i=0;i<c;i++) a[i][i]=1;
	}
	Matrix operator * (Matrix rhs){
		Matrix ans;
		for(int i=0;i<c;i++){
			for(int j=0;j<c;j++){
				LL t=0;
				for(int k=0;k<c;k++){
					t+=1ll*a[i][k]*rhs.a[k][j]%mod;
				}
				ans.a[i][j]=t%mod;
			}
		}
		return ans;
	}
}A,F;
inline Matrix mpow(Matrix a,int x){
	Matrix ans;
	ans.set();
	while(x){
		if(x&1) ans=ans*a;
		a=a*a;
		x>>=1;
	}
	return ans;
}
inline void dfs(int x,int s,int t,int lst,int p){
	if(x==n){
		if(!(p&1)) F.a[s][t]=ADD(F.a[s][t],1);
		return;
	}	
	if(s>>x&1){
		dfs(x+1,s,t|(1<<x),0,p);
		dfs(x+1,s,t|(1<<x),1,p^1);
	}
	else{
		if(lst){
			dfs(x+1,s,t|(1<<x),0,p);
			dfs(x+1,s,t,1,p^1);
		}
		else dfs(x+1,s,t,0,p);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	L=strlen(s+1),c=1<<n;
	A.set();
	for(int i=1;i<=L;i++){
		F.clear();
		for(int t=0;t<c;t++) dfs(0,t,0,s[i]-'0',0);
		A=A*F;
	}
	A=mpow(A,m);
	printf("%d\n",A.a[0][c-1]);
	return 0;
}

