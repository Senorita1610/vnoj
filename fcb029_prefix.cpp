#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string a,b;
string Check(string a, string b){
    if (a.size()>b.size()) return "No";
    for (ll i=0;i<a.size();i++)
        if (a[i]!=b[i]) return "No";
    return "Yes";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    cout<<Check(a,b);
}

