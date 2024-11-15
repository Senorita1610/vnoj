#include<bits/stdc++.h>
using namespace std;
const int N=30;
int t,n,m;
long long dp[N+5][(1<<5)];
bool check(int x,int y) {
	for (int i=0;i<m-1;i++) {
		int t1=(x>>i&1),t2=(x>>(i+1)&1);
		int t3=(y>>i&1),t4=(y>>(i+1)&1);
		if (t1==t2&&t2==t3&&t3==t4) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	long long res=0;
    	cin>>n>>m;
    	if (n<m) swap(n,m);
    	memset(dp,0,sizeof(dp));
    	for (int i=0;i<(1<<m);i++) dp[1][i]=1;
    	for (int i=2;i<=n;i++) {
    		for (int mask=0;mask<(1<<m);mask++) {
    			for (int lastmask=0;lastmask<(1<<m);lastmask++) {
    				if (check(mask,lastmask)) dp[i][mask]+=dp[i-1][lastmask];
    			}
    		}
    	}
    	for (int mask=0;mask<(1<<m);mask++) res+=dp[n][mask];
    	cout<<res<<'\n';
    }
}

