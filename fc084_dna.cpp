#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
string a,s;
ll Check(string a, string b){
    if (a.size()!=b.size()) return 0;
    ll d=0;
    for (ll i=0;i<a.size();i++)
        d+=(a[i]!=b[i]);
    return (d<=2) ? 1 : 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        if (Check(a,s)==1) cout<<i<<" ";
    }
}

