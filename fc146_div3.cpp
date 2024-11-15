#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll ans=inf,a[20];
string n;
void Check(){
    ll s=0,d=0;
    for (ll i=0;i<n.size();i++)
        (a[i]==1) ? d++ : s+=int(n[i])-48;
    if (s%3==0) ans=min(ans,d);
}
void Try(ll i){
    for (ll j=0;j<=1;j++){
        a[i]=j;
        if (i<n.size()-1) Try(i+1);
        else Check();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    Try(0);
    cout<<ans;
}

