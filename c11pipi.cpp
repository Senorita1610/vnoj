#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1e6+5;
set<int>s;
int a[N];
int ans[N];
int pre_full_pos[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<m;i++) cin>>a[i];
		s.clear();
		mem(pre_full_pos,0);
		mem(ans,0);
		bool flag=false;
		for(int i=0;i<m&&!flag;i++){
			if(a[i]){
				set<int>::iterator it=s.lower_bound(pre_full_pos[a[i]]);
				if(it!=s.end()){
					ans[*it]=a[i];
					s.erase(it);
					pre_full_pos[a[i]]=i;
				}
				else flag=true;
			}	
			else s.insert(i);
		}
		if(flag){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i=0;i<m;i++) if(!a[i]) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}

