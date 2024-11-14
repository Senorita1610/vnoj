#include<bits/stdc++.h>
using namespace std;
int m,n,k,res;
vector<vector<int>>a,sum;
vector<vector<pair<int,int>>>b;
int calc(int t) {
	int ans=0;
	sum=vector<vector<int>>(m+2,vector<int>(n+2,0));
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			int temp=(a[i][j]+sum[i][j])%3;
			if (temp==t) continue;
			if (b[i][j].first==0) return 1e9;
			int cur=((t-temp)%3+3)%3;
			ans+=cur;
			int x=b[i][j].first,y=b[i][j].second;
			sum[i][j]+=cur;
			sum[i][y+1]-=cur;
			sum[x+1][j]-=cur;
			sum[x+1][y+1]+=cur;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n>>k;
    a=vector<vector<int>>(m+2,vector<int>(n+2,0));
    b=vector<vector<pair<int,int>>>(m+2,vector<pair<int,int>>(n+2,{0,0}));
    for (int i=1;i<=m;i++) {
    	for (int j=1;j<=n;j++) cin>>a[i][j];
    }
    for (int i=1;i<=k;i++) {
    	int r,c,x,y;
    	cin>>r>>c>>x>>y;
    	b[r][c]={x,y};
    }
    res=min(calc(1),calc(2));
	if (res==1e9) cout<<-1;
	else cout<<res;
}

