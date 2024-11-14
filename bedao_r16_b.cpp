#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,k;
long long a[N+5],b[N+5];
long long res,mx;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        res+=a[i]*b[i];
    }
    for (int i=1;i<=n;i++) {
        long long x=a[i],y=b[i];
        if (x>y) swap(x,y);
        long long temp=min(k,y-x);
        if (temp==k) mx=max(mx,(x+temp)*y-x*y);
        else {
            if ((k-temp)%2==0) mx=max(mx,(y+(k-temp)/2)*(y+(k-temp)/2)-x*y);
            else mx=max(mx,(y+(k-temp)/2)*(y+(k-temp)/2+1)-x*y);
        }
    }
    cout<<res+mx;
}

