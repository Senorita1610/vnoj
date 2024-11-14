#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,m;
ll b[200005];
vector<ll>a;
ll dfs(int x,vector<ll>v){
	if(x>m){
		ll sum=0;
		for(auto k:v) sum+=k;
		return sum;
	}
	if(!v.size()) return 0;
	vector<ll>p,q;
	for(auto k:v){
		if(!(k%b[x])){
			p.push_back(k);
		}
		else{
			q.push_back(k);
		}
	}
	if(x&1) return min(dfs(x+1,p),dfs(x+1,q));
	else return max(dfs(x+1,p),dfs(x+1,q));
}
int main(){
	scanf("%d%d",&n,&m);
	if(m>30){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		a.push_back(x);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	cout<<dfs(1,a)<<endl;
	return 0;
}

