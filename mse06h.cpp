#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>Pair;
struct bit{
	int sz;
	vector<int>v;
	bit(int m) :sz(m+2),v(m+2){
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int w){
		while(x<=sz) v[x]+=w,x+=lowbit(x);
	}
	int all(int x){
		int ret=0;
		while(x>0) ret+=v[x],x-=lowbit(x);
		return ret;
	}
};
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int t,cas=0,n,m,k;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		bit b(m);
		vector<Pair>v(k);
		for(int i=0;i<k;i++) cin>>v[i].first>>v[i].second;
		sort(v.begin(),v.end());
		long long ans=0;
		for(int i=0;i<k;i++){
			b.add(v[i].second,1);
			ans+=i+1-b.all(v[i].second);
		}
		cout<<"Test case "<<(++cas)<<": "<<ans<<endl;
	}
	return 0;
}

