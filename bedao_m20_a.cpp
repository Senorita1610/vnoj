#include<bits/stdc++.h>
using namespace std;
long long m,t,k,n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m;
    while (m--) {
        cin>>t>>k>>n;
        if (n<t) {
            cout<<0<<'\n';
            continue;
        }
        long long dif=n-t+1;
        cout<<(dif+k-1)/k<<'\n';
    }
}

