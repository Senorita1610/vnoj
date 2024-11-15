#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=55;
const LL mod=1e9+7;
int n;
LL k;
struct M{
	int n,m;
	LL a[N][N]={0};
	friend M operator*(M a,M b){
		M c;
		c.n=a.n,
		c.m=b.m;
		for(int i=1;i<=a.n;i++){
			for(int j=1;j<=a.m;j++){
				for(int k=1;k<=b.m;k++){
					c.a[i][k]=(c.a[i][k]+a.a[i][j]*b.a[j][k])%mod;
				}
			}
		}
		return c;
	}
	void pow(M a,LL n,M &ans){
		ans=a,n--;
		while(n){
			if(n&1) ans=ans*a;
			a=a*a,n>>=1;
		}
	}
	void print(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%lld ",a[i][j]);
			}
			printf("\n");
		}
	}
}a,b;
int main(){
	scanf("%d%lld",&n,&k);
	a.n=a.m=n;
	for(int i=1,x;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			a.a[i][j]=x;
		}
	}
	a.pow(a,k,b); LL ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=(ans+b.a[i][j])%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}

