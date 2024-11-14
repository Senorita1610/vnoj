#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<cstring>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e4+5;
int v[N]={};
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		v[i]=x-1;
	}
	vector<int>ans(n+5,1);
	for(int l=0;l<m;l++){
		vector<int>vec(n+5,0),vec1(k+7,0);
		vec1[0]=n;
		for(int r=l;r<min(m,l+k);r++){
			ans[v[r]]=max(ans[v[r]],vec1[vec[v[r]]+1]+1);
			vec[v[r]]++;
			vec1[vec[v[r]]]++;
		}
		for(int i=0;i<n;i++){
			ans[i]=max(ans[i],vec1[vec[i]+1]+1);
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" \n"[i==n-1];
	}
}

