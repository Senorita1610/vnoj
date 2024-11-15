#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int main(){
	cin>>n>>k;
	vector<int>v(n);
	for(auto &c:v)cin>>c;
	vector<int>dp(k+1000,0);
	for(int i=0;i<=k;i++){
		if(dp[i]==1) continue;
		for(auto to:v){
			if(i+to>k) continue;
			dp[i+to]=1;
		}
	}
	if(dp[k]==1){
		cout<<"First\n";
	}else{
		cout<<"Second\n";
	}
}

