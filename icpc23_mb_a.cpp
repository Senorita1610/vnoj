#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=5e2+10;
#define all(s) s.begin(),s.end()
#define endl '\n'
#define int long long
vector<int>p;
int ans=0;
void dfs(int t,int idx){
	if(t==1){
		ans++;
		return;
	}
	for(int i=idx;i<p.size();i++){
		if(t%p[i]==0) dfs(t/p[i],i);
	}
}
void solve(){
	int t;
	cin>>t;
	ans=0;
	dfs(t,2);
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	p.push_back(1);
	p.push_back(1);
	for(int i=2;;i++){
		if(p[i-1]>1e18){
			break;
		}
		p.push_back(p[i-1]+p[i-2]);
	}
	cin>>tc;
	while(tc--){
		solve();
	}
	return 0;
}

