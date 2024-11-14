#include<bits/stdc++.h>
using namespace std;
long long n,p,q,r;
long long calc(long long x) {
    return n/x;
}
long long lcm(long long x,long long y) {
    return x*y/__gcd(x,y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin>>n>>p>>q>>r) {
        cout<<calc(lcm(p,q))+calc(lcm(p,r))+calc(lcm(q,r))-3*calc(lcm(lcm(p,q),r))<<'\n';
    }
}

