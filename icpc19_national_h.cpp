#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int G=3;
const int MOD=998244353;
const int N=(1<<22)+5;
int rev[N],w[N],inv_n;
int bigMod(int a,int e,int mod){
	if(e==-1) e=mod-2;
	int ret=1;
	while(e){
		if(e&1) ret=(ll)ret*a%mod;
		a=(ll)a*a%mod;e>>=1;
	}
	return ret;
}
void prepare(int &n){
	int sz=abs(31 - __builtin_clz(n));
	int r=bigMod(G,(MOD-1)/n,MOD);
	inv_n=bigMod(n,MOD-2,MOD),w[0]=w[n]=1;
	for(int i=1;i<n;i++) w[i]=(ll)w[i-1]*r%MOD;
	for(int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1) | ((i&1)<<(sz-1));
}
void ntt(int *a,int n,int dir){
	for(int i=1;i<n-1;i++){
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	}
	for(int m=2;m<=n;m<<=1){
		for(int i=0;i<n;i+=m){
			for(int j=0;j<(m>>1);j++){
				int &u = a[i+j],&v=a[i+j+(m>>1)];
				int t=(ll)v*w[dir?n-n/m*j:n/m*j]%MOD;
				v=u-t<0?u-t+MOD:u-t;
				u=u+t>=MOD?u+t-MOD:u+t;
			}
		}
	}
	if(dir) for(int i=0;i<n;i++) a[i]=(ll)a[i]*inv_n%MOD;
}
int f_a[N],f_b[N];
vector<int>multiply(vector<int>a,vector<int>b){
	int sz=1,n=a.size(),m=b.size();
	while(sz<n+m-1)sz<<=1;prepare(sz);
	for(int i=0;i<sz;i++) f_a[i]=i<n?a[i]:0;
	for(int i=0;i<sz;i++) f_b[i]=i<m?b[i]:0;
	ntt(f_a,sz,0);
	ntt(f_b,sz,0);
	for(int i=0;i<sz;i++) f_a[i]=(ll)f_a[i]*f_b[i]%MOD;
	ntt(f_a,sz,1);
	return vector<int>(f_a,f_a+n+m-1);
}
int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"10\n";
		return 0;
	}
	int sz=1,tot=9*n+2;
	while(sz<tot) sz<<=1;
	prepare(sz);
	for(int i=0;i<10;i++) f_a[i]=1;
	ntt(f_a,sz,0);
	for(int i=0;i<sz;i++) f_a[i]=bigMod(f_a[i],n-1,MOD);
	ntt(f_a,sz,1);
	vector<int>one(9,1),two(f_a,f_a+tot);
	vector<int>yo=multiply(one,two);
	int pwr = 9*(n-1-(n-1)/2)-1;
	long long ans=0;
	for(int i=0;i<yo.size();i++){
		long long cur=yo[i];
		ans+=cur*cur%MOD,ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}

