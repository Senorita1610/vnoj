#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=11000;
struct Node{
	int w,s;
	long long v;
	void get(){
		scanf("%d%d%lld",&w,&s,&v);
	}
};
Node a[N];
long long f[N*2];
int main(){
	memset(f,0xc7,sizeof f);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i].get();
	sort(a+1,a+1+n,[](const Node &a,const Node &b){
		return a.s+a.w<b.s+b.w;
	});
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i].s;j>=0;j--){
			f[j+a[i].w]=max(f[j+a[i].w],f[j]+a[i].v);
		}
	}
	long long ans=0;
	for(int i=0;i<=20000;i++) ans=max(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}

