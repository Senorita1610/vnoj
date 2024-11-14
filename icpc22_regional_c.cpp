#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
void solve(){
	int n;
	cin>>n;
	vector<int>t1(n+1),t2(n+1);
	for(int i=1;i<=n;i++) cin>>t1[i];
	for(int i=1;i<=n;i++) cin>>t2[i];
	if(n%2==0){
		cout<<"-1\n";
		return;
	}
	int id=1;
	int pos,le;
	vector<int>mm;
	for(int i=1;i<=n;i++){
		if(!t1[i]) pos=i,id=1,le=t2[i];
		else if(!t2[i]) pos=i,id=2,le=t1[i];
		else mm.pb(i);
	}
	cout<<(n-1)/2*10+1<<endl;
	for(int i=0;i<mm.size();i+=2){
		int g1=mm[i],g2=mm[i+1];
		int r1=t1[g1],r2=t2[g1],r3=t1[g2],r4=t2[g2];
		if(id==2) swap(r1,r2),swap(r3,r4);
		cout<<r2<<" "<<r1<<" "<<r4<<" "<<r2<<" "<<le<<" "<<r4<<" "<<r2<<" "<<r3<<" "<<r4<<" "<<le<<" ";
	}
	cout<<le<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

