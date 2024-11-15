#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define i32 INT_MAX
#define i64 LONG_LONG_MAX
#define pii pair<int,int>
#define pll pair<long long,long long>
#define push_back pb
typedef long long ll;
using namespace std;
namespace IO {
	const int MAXSIZE = 1<<20;
	char buf[MAXSIZE],*p1,*p2;
	char pbuf[1<<20],*pp=pbuf;
	static ll sta[35];
	ll top=0;
	inline char gc(){
		return (p1==p2 && (p2=(p1=buf)+fread(buf,1,MAXSIZE,stdin),p1==p2)? EOF : *p1++);
	}
	void read(auto &p){
		ll x=0,f=1;
		char c=gc();
		while(c<48||c>57){
			if(c==45) f=-1;
			c=gc();
		}
		while(c>=48&&c<=57) x=((x<<3)+(x<<1))+(c^48),c=gc();
		p=x*f;
	}
	void push(const char &c){
		if(pp-pbuf==1<<20) fwrite(pbuf,1,1<<20,stdout), pp=pbuf;
		*pp++=c;
	}
	void qflush(){
		fwrite(pbuf,1,pp-pbuf,stdout);
	}
	void print(ll x){
		do{
			sta[top++]=x%10;
			x/=10;
		}while(x);
		while(top) push(sta[--top]+48);
	}
}
using namespace IO;
const int N=1e5+10;
int n;
int a[N],b[N],c[N],dp[N][4];
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]),read(b[i]),read(c[i]);
		dp[i][1]=max(dp[i-1][2],dp[i-1][3])+a[i];
		dp[i][2]=max(dp[i-1][1],dp[i-1][3])+b[i];
		dp[i][3]=max(dp[i-1][1],dp[i-1][2])+c[i];
	}
	print(max(dp[n][1],max(dp[n][2],dp[n][3])));
	qflush();
	return 0;
}

