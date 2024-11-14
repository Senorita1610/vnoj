#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int l[N+5],r[N+5];
int res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n==1) {
        cout<<1000000000;
        return 0;
    }
    l[1]=a[1];
    for (int i=2;i<=n;i++) l[i]=__gcd(l[i-1],a[i]);
    r[n]=a[n];
    for (int i=n-1;i>=1;i--) r[i]=__gcd(r[i+1],a[i]);
    for (int i=1;i<=n;i++) res=max(res,__gcd(l[i-1],r[i+1]));
    cout<<res;
}

