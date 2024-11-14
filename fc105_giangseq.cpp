#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int n,k;
long long a[N+5],dp[N+5];
long long res,lo,hi;
bool check(long long dif) {
    memset(dp,0,sizeof(dp));
    for (long long i=2;i<=n;i++) {
        dp[i]=i-1;
        for (long long j=1;j<i;j++) {
            if (abs(a[i]-a[j])<=dif*(i-j)) dp[i]=min(dp[i],dp[j]+(i-j-1));
        }
    }
    dp[n+1]=n;
    for (int j=1;j<=n;j++) dp[n+1]=min(dp[n+1],dp[j]+(n-j));
    return (min(dp[n+1],dp[n])<=k);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    lo=0,hi=1e12;
    while(lo<=hi) {
        long long mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    cout<<res;
}

