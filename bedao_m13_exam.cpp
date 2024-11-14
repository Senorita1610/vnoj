#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,q,d,x;
void Solve(){
    cin>>q;
    ll kt=1;
    unordered_map <ll,ll> mp;
    for (ll i=1;i<=q;i++){
        cin>>d>>x;
        if (d==1 && kt==1) mp[x]++;
        else if (d==2 && kt==1){
            if (mp[x]!=0) mp[x]--;
            else if (mp[0]!=0) mp[0]--;
            else kt=0;
        }
    }
    (kt==0) ? cout<<"NO"<<endl : cout<<"YES"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

