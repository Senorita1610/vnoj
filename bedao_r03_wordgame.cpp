#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
string a,s;
unordered_map <string,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>s;
        if (i!=1){
            if (mp[s]==1 || s[0]!=a[a.size()-1]){
                cout<<"NO"<<endl<<i;
                return 0;
            }
        }
        mp[s]=1;
        a=s;
    }
    cout<<"YES";
}

