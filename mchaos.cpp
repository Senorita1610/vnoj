#include<bits/stdc++.h>
#define f first
#define se second
#define C(a) memset(a,0,sizeof a)
#define ll long long
using namespace std;
const int maxn=1e5+100;
pair<string,int>s[maxn];
int a[maxn],n;
void add(int x,int y){
	while(x<=n){
		a[x]+=y;
		x+=x&-x;
	}
}
int sum(int x){
	int s=0;
	while(x>0){
		s+=a[x];
		x-=x&-x;
	}
	return s;
}
void init(){
	C(a);
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>s[i].f;
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		reverse(s[i].f.begin(),s[i].f.end());
		s[i].se=i;
	}
	sort(s+1,s+n+1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=i-1-sum(s[i].se);
		add(s[i].se,1);
	}
	printf("%lld\n",ans);
}

