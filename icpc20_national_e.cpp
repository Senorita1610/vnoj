#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5,mod=998244353;
int n;
char s[sz];
ll ten[sz];
struct node{
	ll sum=0,lhs=0,rhs=0;
	int ld=0,rsign=0;
	node operator + (const node &oth) const{
		node res=oth;
		if(rsign){
			if(oth.rsign){
				res.lhs=lhs,res.ld=ld;
				ll add=oth.lhs+ten[oth.ld]*rhs;
				ll &s=res.sum;
				s+=sum;
				if(rsign>0) s+=add;
				else s-=add;
				s%=mod;
			}
			else{
				res=*this;
				res.rhs=(rhs*ten[oth.ld]+oth.lhs)%mod;
			}
		}
		else{
			res.lhs=(oth.lhs+ten[oth.ld]*lhs)%mod;
			res.ld=oth.ld+ld;
		}
		return res;
	}
}tree[sz<<2];
node fnc(int i){
	node now;
	char c=s[i];
	if(isdigit(c)){
		now.lhs=c-'0';
		now.ld=1;
	}
	else if(c=='+') now.rsign=1;
	else now.rsign=-1;
	return now;
}
void form(int u=1,int b=1,int e=n){
	if(b==e){
		tree[u]=fnc(b);
		return;
	}
	int m=(b+e)>>1,x=u<<1,y=x|1;
	form(x,b,m);form(y,m+1,e);
	tree[u]=tree[x]+tree[y];
}
void update(int i,int u=1,int b=1,int e=n){
	if(b>i or e<i) return;
	if(b==e){
		tree[u]=fnc(b);
		return;
	}
	int m=(b+e)>>1,x=u<<1,y=x|1;
	update(i,x,b,m);update(i,y,m+1,e);
	tree[u]=tree[x]+tree[y];
}
node query(int l,int r,int u=1,int b=1,int e=n){
	node nd;
	if(b>r or e<l) return nd;
	if(l<=b and e<=r) return tree[u];
	int m=(b+e)>>1,x=u<<1,y=x|1;
	return query(l,r,x,b,m)+query(l,r,y,m+1,e);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	ten[0]=1;
	for(int i=1;i<=n;i++) ten[i]=ten[i-1]*10%mod;
	form();
	int q;
	cin>>q;
	while(q--){
		char cmd[5];
		scanf("%s",cmd);
		if(cmd[0]=='!'){
			int i;
			char c;
			scanf("%d %c",&i,&c);
			s[i]=c;
			update(i);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			node res=query(l,r);
			ll ans=res.lhs+res.sum+res.rsign*res.rhs;
			ans%=mod;
			if(ans<0) ans+=mod;
			printf("%lld\n",ans);
		}
	}
}

