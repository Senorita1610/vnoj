#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
long long k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--) {
        cin>>s>>k;
        n=s.size();
        bool flag=true;
        s=' '+s;
        for (int i=1;i<=n/2;i++) {
            if (s[i]!=s[n-i+1]) {
                flag=false;
                break;
            }
        }
        if (!flag) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}

