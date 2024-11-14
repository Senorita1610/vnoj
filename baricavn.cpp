#include<bits/stdc++.h>
#define ll long long
#define mkp(x,y) make_pair(x,y)
#define CLR(a,x) memset(a,x,sizeof(a))
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=2e9+5;
int n,k,f[N],last[N];
struct Node {
	int x,y,z,id;
	bool operator < (const Node &rhs) const {
		if(x==rhs.x)return y<rhs.y;
		return x<rhs.x;
	}
}a[N];
int maxx[N],maxy[N];
struct Ans {
	int x,y;
}ans[N];
void update(int now,int from) {
	if(from==0||f[from]<k)return;
	if(f[now]<f[from]-k+a[now].z) {
		f[now]=f[from]-k+a[now].z;
		last[now]=from;
	}
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	int start=1,end=1;
	while(a[start].id!=1)start++;
	while(a[end].id!=n)end++;
	f[start]=a[start].z;
	maxx[a[start].x]=start;
	maxy[a[start].y]=start;
	for(int i=start+1;i<=end;i++) {
		update(i,maxx[a[i].x]);
		update(i,maxy[a[i].y]);
		if(f[i]>f[maxx[a[i].x]])maxx[a[i].x]=i;
		if(f[i]>f[maxy[a[i].y]])maxy[a[i].y]=i;
	}
	printf("%d\n",f[end]);
	return 0;
}

