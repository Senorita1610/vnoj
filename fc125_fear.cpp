#include <bits/stdc++.h>
using namespace std;
 
signed main() {
    int n,m; cin>>n>>m;
    string s,t; cin>>s>>t; 
    int64_t dp[m+2][n+2];
 
    for(int i = 0 ; i <= m ; i++) {
        for(int j = 0 ; j <= n+1 ; j++) {
            dp[i][j] = INT_MAX;
        }
    }
 
    for(int i = 0 ; i <= n+1 ; i++) dp[0][i]=0;
 
    for(int i = 0 ; i < m ; i++) {
        for(int j = 1 ; j <= n ; j++) {
        	  if(s[j-1] != t[i]) continue;
        	dp[i+1][j]=min(dp[i+1][j],min(dp[i][j-1],dp[i][j+1])+1);
          
            for(int k = 1 ; k <= n ; k++) {
                if(s[k-1] == t[i]) {
                    dp[i+1][k] = min(dp[i+1][k],dp[i+1][j] + abs(j-k));
                }
            }
        }
    }
  
    int64_t mn = INT_MAX;
    for(int i = 0 ; i <= n ; i++) {
        mn=min(mn,dp[m][i]);
    }
    if (mn==INT_MAX){
    	cout<<-1<<endl;
    }
    else
    cout << mn-1;
}

