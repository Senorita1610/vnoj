#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b;
vector <ll> v;
ll Check(ll n){
    ll s=n;
    while (s>0){
        if (s%10==0) return 0;
        if (n%(s%10)!=0) return 0;
        s/=10;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    for (ll i=a;i<=b;i++)
        if (Check(i)==1) v.push_back(i);
    cout<<v.size()<<endl;
    for (auto x : v) cout<<x<<" ";
}

