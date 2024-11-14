#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll K=10000;
ll n,ans=0,a[40],x[40]={},mp[40]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
vector <ll> v[K+5];
void Check(){
    if (mp[a[2*n]+1]==0) return;
    ans++;
    if (ans>K) return;
    for (ll i=1;i<=2*n;i++) v[ans].push_back(a[i]);
}
void Try(ll i){
    for (ll j=2;j<=2*n;j++)
        if (x[j]==0){
            x[j]=1;
            a[i]=j;
            if (mp[a[i]+a[i-1]]){
                if (i<2*n) Try(i+1);
                else Check();
            }
            x[j]=0;
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a[1]=1;x[1]=1;
    Try(2);
    cout<<ans<<endl;
    for (ll i=1;i<=min(ans,K);i++){
        for (auto j : v[i]) cout<<j<<" ";
        cout<<endl;
    }
}

