#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=50000,MOD=123456789;
ll t;
string s;
vector <ll> v1;
vector <char> v2;
void Solve(){
    cin>>s;
    ll ans=0,x=0;
    v1.clear();
    v2.clear();
    if (s[0]>='0' && s[0]<='9') v2.push_back('+');
    for (ll i=0;i<s.size();i++)
        if (s[i]>='0' && s[i]<='9') x=(x*10+int(s[i])-48)%MOD;
        else{
            v2.push_back(s[i]);
            if (v2.size()>1) v1.push_back(x);
            x=0;
        }
    if (v1.size()<v2.size()) v1.push_back(x);
    while (!v1.empty()){
        if (v2.back()=='+') ans=(ans+v1.back())%MOD;
        else if (v2.back()=='-') ans=((ans-v1.back())%MOD+MOD)%MOD;
        else v1[v1.size()-2]=(v1[v1.size()-2]*v1[v1.size()-1])%MOD;
        v1.pop_back();
        v2.pop_back();
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

