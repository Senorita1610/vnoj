#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
 
const int mxn = 110;
string arr[mxn];
pii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
 
int dfs(int r,int c){
	arr[r][c] = '.';
	for(auto &d:dir){
		pii nxt = {r+d.fs,c+d.sc};
		if(nxt.fs<0||nxt.sc<0||nxt.fs>=n||nxt.sc>=m||arr[nxt.fs][nxt.sc] == '.')continue;
		dfs(nxt.fs,nxt.sc);
	}
	return 1;
}
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] == '*')ans+=dfs(i,j);
		}
	}
	cout<<ans;
}

