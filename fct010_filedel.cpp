#include <bits/stdc++.h>
#define ll long long int

using namespace std;

unordered_map <char,ll> mp;
unordered_map <ll,ll> mp1;
const ll N=100005;
ll n,q,x[N][30]={},ans;
string s;
char k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    ans=n;
    for (ll i=1;i<=n;i++){
        cin>>s;
        for (ll j=0;j<s.size();j++)
            x[i][int(s[j])-96]=1;
    }
    while (q--){
        cin>>k;
        if (mp[k]==0){
            mp[k]=1;
            for (ll i=1;i<=n;i++)
                if (mp1[i]==0 && x[i][int(k)-96]==1){
                    mp1[i]=1;
                    ans--;
                }
        }
        cout<<ans<<endl;
    }
}

