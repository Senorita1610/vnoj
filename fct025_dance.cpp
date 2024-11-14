#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,k,x,d1=0,d2=0,ans=0,a[N],b[N];
ll Find(ll x){
    ll l=0,r=d2;
    while (l<r){
        ll md=(l+r)/2;
        if (b[md+1]<=x) l=md+1;
        else r=md;
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>x;
        if (x>0){
            d1++;
            a[d1]=x;
        }
        else if (x<=0){
            d2++;
            b[d2]=-x;
        }
    }
    b[0]=-inf;
    sort(a+1,a+d1+1);
    sort(b+1,b+d2+1);
    for (ll i=1;i<=d1;i++) ans+=Find(a[i])-Find(a[i]-k-1);
    cout<<ans;
}

