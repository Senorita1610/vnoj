#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100000;
ll n;
string a[N+5];
unordered_map <string,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for (ll i=1;i<=n;i++)
        if (mp[a[i]]%2){
            cout<<a[i];
            return 0;
        }
}

