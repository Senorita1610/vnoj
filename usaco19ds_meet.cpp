#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &FF){
	T RR=1;FF=0;char CH=getchar();
	for(;!isdigit(CH);CH=getchar())if(CH=='-')RR=-1;
	for(;isdigit(CH);CH=getchar())FF=(FF<<1)+(FF<<3)+(CH^48);
	FF*=RR;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x*=-1;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int MAXN=5e4+10;
struct node{
	int w,x,d;
}a[MAXN];
int n,l,sm,f[MAXN],k,ans;
bool cmp(node x,node y){
	return x.x<y.x;
}
bool check(int x){
    int ll=1,rr=n,s=0;
    for(int i=1;i<=n;i++)
    	if(a[i].d==1)s+=a[i].x+x>=l?a[rr--].w:0;
    	else s+=a[i].x-x<=0?a[ll++].w:0;
    return s*2>=sm;
}
int main(){
	read(n);read(l);
	for(int i=1;i<=n;i++)read(a[i].w),read(a[i].x),read(a[i].d),sm+=a[i].w;
	sort(a+1,a+n+1,cmp);
	int ll=0,rr=INT_MAX>>1;
	while(ll+1<rr){
		int mid=(ll+rr)>>1;
		if(check(mid))rr=mid;
		else ll=mid;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].d==-1){
			int xx=a[i].x-rr*2;
			int lll=0,rrr=k+1;
			while(lll+1<rrr){
				int mid=(lll+rrr)>>1;
				if(f[mid]>=xx)rrr=mid;
				else lll=mid;
			}
			ans+=k-rrr+1;
		}else{
			f[++k]=a[i].x;
		}
	}cout<<ans;
	return 0;
}

