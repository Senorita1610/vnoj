#define re return
#define dl '\n'
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	if(n==1){
		cout<<1<<dl<<1<<dl;
		re;
	}
	if(n%4==0){
		cout<<n<<dl;
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		cout<<dl;
	}
	else if(n%4==1){
		cout<<n-1<<dl;
		for(int i=1;i<=n;i++){
			if(i==(n-1)) continue;
			else cout<<i<<" ";
		}
		cout<<dl;
	}else if(n%4==2){
		cout<<n-1<<dl;
		for(int i=2;i<=n;i++){
			cout<<i<<" ";
		}
		cout<<dl;
	}else{
		cout<<n-1<<dl;
		for(int i=1;i<n;i++){
			cout<<i<<" ";
		}
		cout<<dl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	cin>>_;
	while(_--){
		solve();
	}
}

