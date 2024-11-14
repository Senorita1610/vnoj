#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll x[500],f[500],ans=-inf;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=0;i<s.size();i++){
        f[i]=inf;
        x[i]=int(s[i]);
    }
    for (ll i=0;i<s.size();i++){
        ll z=upper_bound(f,f+s.size(),x[i])-f;
        ans=max(ans,z+1);
        f[z]=x[i];
    }
    cout<<ans;
}

