#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll z=1111111,N=100005;
unordered_map <ll,ll> mp;
ll t,n,a[z],o[100005],x[100005],d=0;
void SangNt(){
    for (ll i=1;i<=z;i++) a[i]=1;
    a[1]=0;
    ll i=1;
    while (i<=sqrt(z)){
        while (a[i]==0) i++;
        for (ll j=2;j<=z/i;j++)
            a[i*j]=0;
        i++;
    }
}
ll Find(ll l, ll r, ll n){
    ll md=(l+r)/2;
    if (l==r) return x[l];
    if (x[md+1]>n) return Find(l,md,n);
    else return Find(md+1,r,n);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SangNt();
    for (ll i=1;i<=z;i++)
        if (a[i]==1){
            d++;
            o[d]=i;
        }
    for (ll i=1;i<d;i++)
        x[i]=o[i]*o[i+1];
    cin>>t;
    while (t--){
        cin>>n;
        cout<<n-Find(1,d,n)<<endl;
    }
}

