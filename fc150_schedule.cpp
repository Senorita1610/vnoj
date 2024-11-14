#include<bits/stdc++.h>
using namespace std;
long long n,m,x,mx,res,mod=1e9+7;
long long power(long long base, long long k) {
    if (k==0) return 1;
    if (k==1) return base%mod;
    long long temp=power(base,k/2);
    temp=temp*temp;
    temp%=mod;
    if (k%2==1) temp*=base;
    return temp%mod;
}
int main() {
    cin>>n>>m;
    if (m==1) {
        for (int i=1;i<=n;i++) {
            cin>>x;
            res+=power(2,x);
            res%=mod;
        }
        cout<<res;
    } else {
        for (int i=1;i<=n;i++) {
            cin>>x;
            mx=max(mx,x);
        }
        cout<<power(2,mx);
    }
}

