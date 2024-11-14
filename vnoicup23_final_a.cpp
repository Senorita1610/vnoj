#include<bits/stdc++.h>
using namespace std;
int t;
const int N=2e5;
int n;
long long a[N+5];
int res;
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        res=n;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=n-1;i>=1;i--) {
            if (a[i]<a[i+1]) {
                a[i]+=a[i+1];
                res--;
            }
        }
        cout<<res<<endl;
    }
}

