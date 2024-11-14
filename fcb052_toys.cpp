#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,M,a,x=1;
unordered_map <ll,ll> mp;
vector <ll> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>M;
    for (ll i=1;i<=n;i++){
        cin>>a;
        mp[a]=1;
    }
    while (1){
        while (mp[x]==1) x++;
        if (M<x) break;
        else{
            M-=x;
            v.push_back(x);
        }
        x++;
    }
    cout<<v.size()<<endl;
    for (auto x : v) cout<<x<<" ";
}

