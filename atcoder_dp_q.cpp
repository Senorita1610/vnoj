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
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1; ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
#define N 500010
#define lowbit(x) ((-x)&x)
ll n,h[N],d[N];
ll tr[N],f,cnt;
void add(ll x,ll y){
	for(ll i=x;i<=n;i+=lowbit(i)) tr[i]=max(tr[i],y);
}
ll ask(ll x){
	ll res=0;
	for(ll i=x;i;i-=lowbit(i)) res=max(res,tr[i]);
	return res;
}
signed main(){
	scanf("%d",&n);
	for(ll i=1;i<=n;i++) h[i]=read();
	for(ll i=1;i<=n;i++) d[i]=read();
	for(ll i=1;i<=n;i++) {
		f=ask(h[i]-1)+d[i];
		add(h[i],f);
		cnt=max(cnt,f);
	}
	printf("%lld",cnt);
	return 0;
}

