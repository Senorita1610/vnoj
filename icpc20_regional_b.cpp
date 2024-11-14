#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int grid[105][105];
void even(int n,vector<pair<int,int>>&v){
	for(int j=0;j<n;j++) v.emplace_back(0,j);
	for(int j=n-1;j>=0;j--){
		int cur=(j%2==0?n-1:1);
		int del=(j%2==0?-1:1);
		for(int k=0;k<n-1;k++){
			v.emplace_back(cur,j);
			cur+=del;
		}
	}
	return;
}
void mov(pair<int,int>&cur,pair<int,int>del){
	cur.first+=del.first;
	cur.second+=del.second;
}
void odd(int n,int r,int c,vector<pair<int,int>>&v){
	pair<int,int>cur(r,c);
	int wall;
	if(c==0){
		for(int i=0;i<r+1;i++){
			v.push_back(cur);
			mov(cur,make_pair(-1,0));
		}
		cur={0,1};
		for(int i=0;i<r+1;i++){
			v.push_back(cur);
			mov(cur,make_pair(1,0));
		}
		for(int i=0;r+1+i<n;i++){
			cur=(i%2==0?make_pair(r+1+i,1):make_pair(r+1+i,0));
			pair<int,int>del=(i%2==0?make_pair(0,-1):make_pair(0,1));
			for(int j=0;j<2;j++){
				v.push_back(cur);
				mov(cur,del);
			}
		}
		wall=1;
	}
	else if(r==n-1){
		for(int j=0;j<c+1;j++){
			v.push_back(cur);
			mov(cur,{0,-1});
		}
		for(int j=0;j<c+2&&j<n;j++){
			cur=(j%2==0?make_pair(n-2,j):make_pair(0,j));
			pair<int,int>del=(j%2==0?make_pair(-1,0):make_pair(1,0));
			for(int i=0;i<n-1;i++){
				v.push_back(cur);
				mov(cur,del);
			}
		}
		if(c+1<n) v.push_back({r,c+1});
		wall=c+1;
	}
	else if(r%2==0){
		for(int i=0;i<r+1;i++){
			v.push_back(cur);
			mov(cur,{-1,0});
		}
		for(int i=0;i<r+1;i++){
			cur=(i%2==0?make_pair(i,c-1):make_pair(i,0));
			pair<int,int>del=(i%2==0?make_pair(0,-1):make_pair(0,1));
			for(int j=0;j<c;j++){
				v.push_back(cur);
				mov(cur,del);
			}
		}
		for(int j=0;j<c+1;j++){
			cur=(j%2==0?make_pair(r+1,j):make_pair(n-1,j));
			pair<int,int>del=(j%2==0?make_pair(1,0):make_pair(-1,0));
			for(int i=0;i<n-r-1;i++){
				v.push_back(cur);
				mov(cur,del);
			}
		}
		wall=c;
	}
	else{
		for(int j=c;j>=0;j--){
			cur=(j%2==0?make_pair(0,j):make_pair(r,j));
			pair<int,int>del=(j%2==0?make_pair(1,0):make_pair(-1,0));
			for(int i=0;i<r+1;i++){
				v.push_back(cur);
				mov(cur,del);
			}
		}
		for(int i=0;r+i+1<n;i++){
			cur=(i%2==0?make_pair(r+1+i,0):make_pair(r+1+i,c));
			pair<int,int>del=(i%2==0?make_pair(0,1):make_pair(0,-1));
			for(int j=0;j<c+1;j++){
				v.push_back(cur);
				mov(cur,del);
			}
		}
		wall=c;
	}
	for(int i=n-1;i>=0;i--){
		cur=(i%2==0?make_pair(i,wall+1):make_pair(i,n-1));
		pair<int,int>del=(i%2==0?make_pair(0,1):make_pair(0,-1));
		for(int j=0;j<n-1-wall;j++){
			v.push_back(cur);
			mov(cur,del);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin>>tc;
	for(int cs=1;cs<=tc;cs++){
		int n;
		cin>>n;
		int r,c;
		cin>>r>>c;
		r--,c--;
		memset(grid,0,sizeof(grid));
		vector<pair<int,int>>v;
		if(n%2==0){
			even(n,v);
		}
		else{
			if((r+c)%2==1){
				cout<<"NO\n";
				continue;
			}
			else{
				odd(n,r,c,v);
			}
		}
		auto it=find(v.begin(),v.end(),make_pair(r,c));
		rotate(v.begin(),it,v.end());
		int cnt=0;
		for(auto [x,y]:v){
			grid[x][y]=++cnt;
		}
		cout<<"YES\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

