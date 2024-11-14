#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long a[N+5];
bool sq(long long x,long long y) {
	long long t=x*y/__gcd(x,y);
	return ((long long)sqrt(t)*(long long)sqrt(t)==t);
}
long long dp[N+5][2];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[1][1]=1;
    for (int i=2;i<=n;i++) {
    	dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
    	if (sq(a[i-1],a[i])) dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
    	else dp[i][0]=dp[i-1][1]; 
    }
    cout<<min(dp[n][0],dp[n][1]);
}

