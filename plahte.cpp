#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+2;
int n,m;long long a[N],b[N];
void add(int x,int y,int c,int d){
	if(c<d) swap(x,y),swap(c,d);
	int p=max(x,y);
	if(d<p) a[p]+=d-y+1;
	else b[p]+=2,b[d]-=2,
		a[p]+=p*2-x-y+1,a[d+1]-=d-x;
	a[c+1]-=d-y+1;
}
int main(){
	scanf("%d",&n);
	for(int x,y,c,d;n--;){
		scanf("%d%d%d%d",&x,&y,&c,&d);
		if(c<0){int tmp=x;x=-c,c=-tmp;}
		if(d<0){int tmp=y;y=-d,d=-tmp;}
		if(x<0) add(0,y,c,d),add(1,y,-x,d);
		else if(y<0) add(x,0,c,d),add(x,1,c,-y);
		else add(x,y,c,d);
	}
	for(int i=1;i<N;++i) b[i]+=b[i-1],a[i]+=a[i-1]+b[i-1];
	for(int i=1;i<N;++i) a[i]+=a[i-1];
	scanf("%d",&m);
	for(int x;m--;){
		scanf("%d",&x);
		printf("%lld\n",a[x]);
	}
	return 0;
}

