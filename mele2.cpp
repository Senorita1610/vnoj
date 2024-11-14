#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
struct node{
	ll a,b;
	node(){
	}
	node(ll _a,ll _b){
		a=_a;
		b=_b;
	}
};
queue<node>Q;
ll p[100005],h,a,b,c;
int main(){
	while(scanf("%lld",&h)!=-1){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a>b) swap(a,b);
		node top,next;
		while(!Q.empty()) Q.pop();
		memset(p,-1,sizeof(p));
		p[0]=0;
		Q.push(node(0,0));
		while(!Q.empty()){
			top=Q.front();
			Q.pop();
			next=node((top.a+a)%c,top.b+a);
			if(p[next.a]==-1||p[next.a]>next.b){
				p[next.a]=next.b;
				Q.push(next);
			}
			next=node((top.a+b)%c,top.b+b);
			if(p[next.a]==-1||p[next.a]>next.b){
				p[next.a]=next.b;
				Q.push(next);
			}
		}
		ll ans=0,i;
		for(i=0;i<c&&i<h;i++) if(p[i]!=-1&&p[i]<h) ans+=(h-1-p[i])/c+1;
		printf("%lld\n",ans);
	}
	return 0;
}

