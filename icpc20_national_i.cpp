#include<iostream>
#include<cstdio>
#define mod 1000000007
#define maxx 2000010
using namespace std;
int f[maxx],fac[maxx],invfac[maxx];
inline int C(int x,int y){
	if(x<y||y<0) return 0;
	return 1ll*fac[x]*invfac[y]%mod*invfac[x-y]%mod;
}
inline int qpower(int a,int k){
	int ans=1;
	for(;k;k>>=1,a=1ll*a*a%mod) if(k&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int inv(int x){
	return qpower(x,mod-2);
}
int main(){
	f[0]=0,f[1]=1;
	for(int i=2;i<maxx;i++) f[i]=(f[i-1]+f[i-2])%mod;
	fac[0]=1;
	for(int i=1;i<maxx;i++) fac[i]=fac[i-1]*1ll*i%mod;
	invfac[maxx-1]=inv(fac[maxx-1]);
	for(int i=maxx-2;i>=0;i--) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	int x,y;
	scanf("%d%d",&x,&y);
	int ans=0;
	for(int i=1;i<=max(x,y);i++) ans=(ans+1ll*f[i]*(C(x+y-i-1,y-1)+C(x+y-i-1,y-i)))%mod;
	printf("%d\n",ans);
	return 0;
}

