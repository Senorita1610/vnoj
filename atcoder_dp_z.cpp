#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
char buf[1<<20],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);ch=getchar();
	}
	return x*f;
}
#define N 200010
#define y(u) double(f[u]+h[u]*h[u])
#define k(u,v) double(y(u)-y(v))/double(h[u]-h[v])
#define fr q[l]
#define ed q[r]
ll n,c,h[N],f[N],l=1,r=1,q[N]={0,1};
signed main(){
	n=read(),c=read();
	for(int i=1;i<=n;i++) h[i]=read();
	for(int i=2;i<=n;i++){
		while(l<r&&k(fr,q[l+1])<=h[i]<<1) ++l;
		f[i]=f[fr]+(h[i]-h[fr])*(h[i]-h[fr]) +c;
		while(l<r&&k(q[r-1],ed)>=k(ed,i)) --r;
		q[++r]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}

