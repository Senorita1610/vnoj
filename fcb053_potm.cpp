#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5],sum[N+5];
int main() {
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    while (q--) {
        int type,x,k;
        cin>>type>>x>>k;
        if (type==0) cout<<sum[k]<<endl;
        else cout<<sum[x]-sum[x-k]<<endl;
    }
}

