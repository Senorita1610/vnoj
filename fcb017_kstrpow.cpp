#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll k;
string t,s;
ll Check(string a, string b){
    if (a.size()%b.size()!=0) return 0;
    for (ll i=0;i<a.size();i++)
        if (a[i]!=a[i%b.size()]) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>t>>k;
    if (Check(t,s)==0){
        cout<<"NO";
        return 0;
    }
    (s.size()*k==t.size()) ? cout<<"YES" : cout<<"NO";
}

