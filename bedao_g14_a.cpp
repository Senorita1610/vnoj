#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n+1;i++) cin>>a[i];
    sort(a+1,a+2+n);
    for (int i=1;i<=n;i++) {
        if ((a[i]+1)==a[i+1]) {
            cout<<a[i]<<' '<<a[i+1];
            return 0;
        }
    }
}

