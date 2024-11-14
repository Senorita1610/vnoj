#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+100;
const int maxN=1e5+100;
const int MOD=998244353;
int dp[105][maxN][2];
int main() {
	int n,w,h;
    cin>>n>>w>>h;
    vector<vector<int>>a(n+1,vector<int>(2));
    int sum_c=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
        sum_c+=a[i][1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum_c;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum_c;j++){
            dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]);
            dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
            if(j>=a[i][1]){
                dp[i][j][0]=min(dp[i][j][0],dp[i-1][j-a[i][1]][0]+a[i][0]);
                dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-a[i][1]][1]+a[i][0]);
                if(a[i][0]<=h){
                    dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-a[i][1]][0]);
                }
            }
        }
    }
    int ans=sum_c;
    while(ans>=0&&min(dp[n][ans][0],dp[n][ans][1])>w) ans--;
    cout<<ans<<'\n';
}

