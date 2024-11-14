#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long
#define pb push_back
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>>v;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v.pb({x,y});
		}
		cout<<"YES"<<endl;
		cout<<7*n<<endl;
		for(int i=0;i<n;i++){
			pair<int,int>p=v[i];
			cout<<p.f<<" "<<p.s<<" "<<3<<endl;
			cout<<p.f+1<<" "<<p.s<<" "<<2<<endl;
			cout<<p.f-1<<" "<<p.s<<" "<<2<<endl;
			cout<<p.f<<" "<<p.s+1<<" "<<2<<endl;
			cout<<p.f<<" "<<p.s-1<<" "<<2<<endl;
			cout<<p.f+1<<" "<<p.s+1<<" "<<2<<endl;
			cout<<p.f-1<<" "<<p.s-1<<" "<<2<<endl;
		}
	}
}

