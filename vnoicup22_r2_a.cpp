#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100000;
ll n,m;
tuple <ll,ll,ll> a[N+5];
bool comp(const tuple <ll,ll,ll> a, const tuple <ll,ll,ll> b){
    return get<1>(a)<get<1>(b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++){
        get<2>(a[i])=i;
        cin>>get<0>(a[i])>>get<1>(a[i]);
    }
    sort(a+1,a+n+1,comp);
    for (ll i=1;i<=n;i++)
        if (get<0>(a[i])>get<1>(a[1])){
            cout<<"YES"<<endl<<get<2>(a[i])<<" "<<get<2>(a[1]);
            return 0;
        }
    cout<<"NO";
}

