#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
const int N=1e5;
const int mod=1e9+7;
using namespace std;
#define ll long long
bool v[N+5];
int p[N+5];
int tot;
int a[1010];
inline int phi(int x){
	int tt=1;
	for(int i=1;i<=tot;i++){
		int t=1;
		while(x%p[i]==0){
			x/=p[i];
			t*=p[i];
		}
		tt*=(t-t/p[i]);
		if(x==1) break;	
	}
	return tt;
}
inline int check(int x,int y){
	while(y>0){
		if(x%a[y]==0) return y;
		y--;
	}
	return 0;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		ll ans=1;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		memset(v,0,sizeof v);
		memset(p,0,sizeof p);
		tot=0;
		for(int i=2;i<=n;i++) if(!v[i]){
			p[++tot]=a[i];
			for(int j=i+1;j<=n;j++) if(a[j]%a[i]==0) v[j]=1;
		}
		for(int i=2;i<=n;i++) ans=(ans*phi(a[i]))%mod;
		printf("%I64d\n",ans);
	}
	return 0;
}

