#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int t,n;
long long a[N+5];
long long dp[N+5][(1<<10)+5];
bool check(long long x) {
    bool c[10]={};
    string s=to_string(x);
    for (auto i:s) {
        if (c[i-'0']) return false;
        c[i-'0']=true;
    }
    return true;
}
int bt(long long x) {
    string s=to_string(x);
    int bit=0;
    for (auto i:s) {
        bit|=(1<<(i-'0'));
    }
    return bit;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--) {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        memset(dp,0,sizeof(dp));
        long long res=0;
        for (int i=1;i<=n;i++) {
            for (int mask=0;mask<(1<<10);mask++) {
                dp[i][mask]=dp[i-1][mask];
                res=max(res,dp[i][mask]);
            }
            if (!check(a[i])) continue;
            int bit=bt(a[i]);
            for (int mask=0;mask<(1<<10);mask++) {
                if (!(mask&bit)) {
                    dp[i][mask|bit]=max(dp[i][mask|bit],dp[i-1][mask]+a[i]);
                    res=max(res,dp[i][mask|bit]);
                }
            }
        }
        cout<<res<<'\n';
    }
}

