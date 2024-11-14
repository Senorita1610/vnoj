#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lim=105;
ll S[lim],M[lim],fact[lim],C[lim][lim][lim];
const ll mod=1e9+7;
ll mpow(ll a,ll b){
	if(b==1) return a%mod;
	ll x=mpow(a,b/2);
	if(b%2) return (((x*x)%mod)*a)%mod;
	else return (x*x)%mod;
}
ll minv(ll n){
	return mpow(n,mod-2);
}
int n,m,k;
void init(){
	fact[0]=1;
	for(int i=1;i<lim;i++) fact[i]=(i*fact[i-1])%mod;
	memset(C,0,sizeof C);
	C[1][0][0]=1;
	for(int i=1;i<lim;i++){
		for(int j=0;j<=i;j++){
			if(j==0) C[1][i][j]=1;
			else if(i!=0){
				C[1][i][j]=(C[1][i-1][j]+C[1][i-1][j-1])%mod;
			}
		}
	}
	
	for(int t=2;t<lim;t++){
		for(int i=0;i<lim;i++){
			for(int j=0;j<=i;j++){
				C[t][i][j]=(C[1][i][j]*C[t-1][i][j])%mod;
			}
		}
	}
}
ll f[lim][lim];
ll solve(){
	for(int t=1;t<=n;t++){
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int i=1;i<=k;i++){
			for(int j=0;j<=m;j++){
				for(int l=0;l<=j;l++){
					f[i][j]+=f[i-1][l]*C[t][m-l][j-l];
					f[i][j]%=mod;
				}
			}
		}
		M[t]=f[k][m];
	}
	memset(S,0,sizeof S);
	S[0]=1;
	S[1]=M[1];
	for(int p=2;p<=n;p++){
		for(int j=1;j<=p;j++){
			int sign=1;
			if(j%2==0) sign=-1;
			S[p]+=sign*S[p-j]*M[j];
			S[p]%=mod;
		}
		S[p]*=minv(p);
		S[p]%=mod;
	}
	return ((S[n]*fact[n]%mod)+mod)%mod;
}
int main(){
	init();
	while(cin>>n>>m>>k){
		cout<<solve()<<endl;
	}
	return 0;
}

