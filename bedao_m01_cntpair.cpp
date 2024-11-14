#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int t;
long long c1,c2;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>t;
        if (t%2==0) c1++;
        else c2++;
    }
    cout<<c1*(c1-1)/2+c2*(c2-1)/2;
}

