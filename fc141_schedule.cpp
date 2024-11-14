#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000000;
ll n,ans=0,cnt=0;
pair <ll,ll> a[N*2+5];
bool comp(const pair <ll,ll> a, pair <ll,ll> b){
    return (a.first<b.first || (a.first==b.first && a.second<b.second));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i*2-1].first>>a[i*2].first;
        a[i*2-1].second=1;
        a[i*2].second=0;
    }
    sort(a+1,a+2*n+1,comp);
    for (ll i=1;i<=2*n;i++)
        if (!a[i].second) cnt--;
        else{
            ans+=cnt;
            cnt++;
        }
    cout<<ans;
}

