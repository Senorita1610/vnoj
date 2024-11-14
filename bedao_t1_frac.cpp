#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105;
vector <ll> v;
ll n,t=1,a[N],ans=1;
unordered_map <ll,ll> mp,mp1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if (n==0){
        cout<<"impossible";
        return 0;
    }
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        ll x=a[i];
        if (x<=0){
            cout<<"impossible";
            return 0;
        }
        for (ll j=2;j<=sqrt(x);j++)
            if (x%j==0){
                if (mp[j]==0) v.push_back(j);
                while (x%j==0){
                    x/=j;
                    mp[j]++;
                }
            }
        if (x>1){
            if (mp[x]==0) v.push_back(x);
            mp[x]++;
        }
    }
    for (ll i=1;i<=n;i++){
        for (ll j=2;j<=sqrt(a[i]);j++)
            if (a[i]%j==0){
                ll d=0;
                while (a[i]%j==0){
                    d++;
                    a[i]/=j;
                }
                mp1[j]=max(mp1[j],d);
            }
        if (a[i]>1) mp1[a[i]]=max(mp1[a[i]],t);
    }
    for (ll i=0;i<v.size();i++)
        for (ll j=1;j<=mp[v[i]]-mp1[v[i]];j++)
            ans*=v[i];
    cout<<ans;
}

