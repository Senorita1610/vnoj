#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,a[N],b[N],c[N],ans=0,t=0;
ll Get(ll l, ll r){
    ll l1=l,r1=r-1;
    while (1==1){
        while (a[l1]*b[r]>=a[r]*b[l1] && l1<=r1) l1++;
        while (a[r1]*b[r]<=a[r]*b[r1] && l1<=r1) r1--;
        if (l1>=r1) break;
        swap(a[l1],a[r1]);
        swap(b[l1],b[r1]);
        swap(c[l1],c[r1]);
    }
    swap(a[l1],a[r]);
    swap(b[l1],b[r]);
    swap(c[l1],c[r]);
    return l1;
}
void Quick_Sort(ll l, ll r){
    if (l<r){
        ll md=Get(l,r);
        Quick_Sort(l,md-1);
        Quick_Sort(md+1,r);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++) cin>>b[i];
    for (ll i=1;i<=n;i++) c[i]=i;
    Quick_Sort(1,n);
    for (ll i=1;i<=n;i++){
        t+=b[i];
        ans+=t*a[i];
    }
    cout<<ans<<endl;
    for (ll i=1;i<=n;i++) cout<<c[i]<<" ";
}

