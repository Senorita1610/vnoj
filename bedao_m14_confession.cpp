#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll t,n,k;
ll Check(string s, ll x, ll y){
    while (x<y){
        if (s[x]!=s[y]) return 0;
        x++;
        y--;
    }
    return 1;
}
void Solve(){
    cin>>n>>k>>s;
    if (Check(s,k,n-k-1)==0){
        cout<<"No"<<endl;
        return;
    }
    ll x[30]={};
    for (ll i=n-k;i<n;i++) x[int(s[i])-96]++;
    for (ll i=0;i<k;i++) x[int(s[i])-96]--;
    for (ll i=1;i<=26;i++)
        if (x[i]!=0){
            cout<<"No"<<endl;
            return;
        }
    cout<<"Yes"<<endl;
    for (ll i=n-1;i>=n-k;i--) cout<<s[i];
    for (ll i=k;i<n;i++) cout<<s[i];
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

