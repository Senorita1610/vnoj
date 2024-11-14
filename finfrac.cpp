#include<cstdio>
using namespace std;
typedef long long ll;
ll dfs(ll a,ll b,ll c,ll d){
	ll k=a/b;
	a-=b*k;c-=d*k;
	if(c>d) return 1;
	if(a==0) return d/c+1;
	return d*dfs(d,c,b,a)/c+1;
}
int main(){
	ll a,b,c,d,y;
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)==4){
		y=dfs(a,b,c,d);
		printf("%lld/%lld\n",a*y/b+1,y);
	}
}

