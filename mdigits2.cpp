#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string n,s="";
string Change(ll x){
    ostringstream d;
    d<<x;
    return d.str();
}
ll Check(){
    if (s.size()<n.size()) return 0;
    for (ll i=0;i<n.size();i++)
        if (n[n.size()-i-1]!=s[s.size()-i-1]) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;;i++){
        string t=Change(i);
        for (ll j=0;j<t.size();j++){
            s+=t[j];
            if (Check()){
                cout<<s.size()-n.size()+1;
                return 0;
            }
        }
    }
}

