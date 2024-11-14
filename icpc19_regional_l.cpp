#include<bits/stdc++.h>
using namespace std;
int n,a[101][101],mt[101],k;
bool mark[101],used[101],used1[101],dd[101];
vector<int>g[101];
bool try_kuhn(int u){
	if(used[u]) return false;
	used[u]=true;
	for(int v:g[u]){
		if(mt[v]==-1||try_kuhn(mt[v])){
			mt[v]=u;
			return true;
		}
	}
	return false;
}
void matching(int val){
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0) g[i].push_back(j);
		}
	}
	memset(mt,-1,sizeof(mt));
	memset(used,false,sizeof(used));
	memset(used1,false,sizeof(used1));
	for(int u=1;u<=n;u++){
		for(int v:g[u]){
			if(mt[v]==-1){
				mt[v]=u;
				used1[u]=true;
				break;
			}
		}
	}
	for(int u=1;u<=n;u++){
		if(used1[u]) continue;
		for(int i=1;i<=n;i++) used[i]=false;
		try_kuhn(u);
	}
	for(int j=1;j<=n;j++) {
		if(mt[j]!=-1) a[mt[j]][j]=val;
	}
}
bool check_NO(){
	for(int i=1;i<=n;i++){
		memset(dd,false,sizeof(dd));
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!dd[a[i][j]]) ++cnt,dd[a[i][j]]=true;
		}
		if(cnt!=n) return true;
	}
	return false;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			mark[a[i][j]]=true;
		}
	}
	for(int i=1;i<=n;i++){
		if(mark[i]) continue;
		matching(i);
	}
	if(check_NO()){
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

