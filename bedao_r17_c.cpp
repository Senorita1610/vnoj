#include<bits/stdc++.h>
using namespace std;
const int K=1e5,N=100;
int n,k;
int a[N+5];
int dp[K+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) {
        for (int j=1;j<=n;j++)
            if (i>=a[j])
                dp[i]=max(dp[i],i-dp[i-a[j]]);
    }
    cout<<dp[k];
}

