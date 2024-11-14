#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<string>
#include<unordered_map>
#include <queue>
#include<cstring>
#include<cassert>
#include<limits.h>
#include<cmath>
#include<set>
#include<algorithm>
#include<bitset> 
#include<stack>
using namespace std;
#define ll long long
#define f first
#define endl "\n"
#define s second
#define pii pair<int,int>
#define pppiiii pair<pii,pii>
#define ppii pair<int,pii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#define int long long
const int mod=998244353,mxn=2e5+5,lg=30,inf=1e18,minf=-1e9,Mxn=100000,root=700;
int n,m;
void setIO(string name){		
	ios_base::sync_with_stdio(0); cin.tie(0);		
	freopen((name+".in").c_str(),"r",stdin);		
	freopen((name+".out").c_str(),"w",stdout);	
}
vector<int>v;
vector<int>all;
bool check(int a,int id){
	
	vector<int>l,r;
	l.pb(v[0]);
	int last=-1;
	for(int i=1;i<n;i++){
		if(r.size()>1&&v[i]-r.back()==last)r.pb(v[i]);
		else if(v[i]-l.back()==a)l.pb(v[i]);
		else{
			if(r.size()==1)last=v[i]-r.back();
			else if(r.size()>1)return false;
			r.pb(v[i]);
		}
	}
	if(l.size()==0&&r.size()==0)return false;
	if(l.size()==0||r.size()==0){
		if(l.size()<r.size())swap(l,r);
		r.pb(l.back());
		l.pop_back();
	}
	cout<<l.size()<<'\n';
	for(auto i:l)cout<<i<<" ";
	cout<<'\n';
	cout<<r.size()<<"\n";
	for(auto i:r)cout<<i<<" ";
	return true;
}
int32_t main(){
	//setIO("lifeguards");
	fastio
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i];
	sort(all(v));
	int last=-1;
	for(int i=0;i<1;i++){
		for(int j=i;j<min(n,3ll);j++){
			if(check(v[j]-v[i],i))return 0;
		}
	}
	cout<<-1;
	return 0;
	//brute
}

