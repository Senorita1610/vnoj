#include<bits/stdc++.h>
#define pb push_back
#define sz(X) ((int)(X).size())
#define all(X) X.begin(),X.end()
#define ll long long
#define pi pair<int,int>
const int N=1e3+5,MOD=100;
const int oo=1e9;
using namespace std;
string a,aa;
int k,tc,n;
int Next[N];
int memo[N][5*N];
int power(int x,int p){
	if(!p) return 1;
	if(p==1) return x;
	int r=power(x,p/2);
	return r*r*power(x,p&1);
}
int solve(int indx,int rem){
	if(indx==n) return oo*(rem!=0);
	int &ret=memo[indx][rem];
	if(~ret) return ret;
	int curr=0,cur=1;
	ret=oo;
	for(int i=indx;i<n;i++){
		curr+=(aa[i]-'0')*cur;
		cur*=10;
		if(curr>rem) break;
		ret=min(ret,((i+1)!=n)+solve(i+1,rem-curr));
	}
	return ret;
}
void solve(){
	k=0;
	int cur=1;
	cin>>a;
	memset(memo,-1,sizeof(memo));
	while(a.back()!='=') k+=(cur*(a.back()-'0')),cur*=10,a.pop_back();
	a.pop_back();
	int cnt=0;
	while(sz(a)){
		if(a.back()=='0'){
			cnt++;
			if(cnt<=3) aa.pb(a.back());
		}else{
			cnt=0;
			aa.pb(a.back());
		}
		a.pop_back();
	}
	n=sz(aa);
	cout<<solve(0,k)<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}

