#include<bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int sz=1e4+7;
string s1,s2;
char c;
int t,say=0;
map<string,int>m;
bool check=false;
vector<int>g[sz];
int used[sz];
void dfs(int node){
	if(used[node]) return;
	used[node]=1;
	for(int i:g[node]){
		if(used[i]==1){
			check=true;
		}
		else if(used[i]==0){
			dfs(i);
		}
	}
	used[node]=2;
}
signed main(){
	speed;
	cin>>t;
	while(t--){
		cin>>s1>>c>>s2;
		if(m[s1]==0){
			say++;
			m[s1]=say;
		}
		if(m[s2]==0){
			say++;
			m[s2]=say;
		}
		if(c=='>'){
			g[m[s2]].push_back(m[s1]);
		}else{
			g[m[s1]].push_back(m[s2]);
		}
	}
	for(int i=1;i<=say;i++){
		if(!used[i]) dfs(i);
		if(check) break;
	}
	cout<<(check?"impossible":"possible");
}

