#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,k;
string n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--){
        cin>>n>>k;
        ll s=0;
        for (ll i=0;i<n.size();i++) s=s+int(n[i])-48;
        if (k==1) cout<<"YES"<<endl;
        else if (k==2) (n[n.size()-1]%2==0) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
        else if (k==3) (n[n.size()-1]%2==0 && s%3==0) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}

