#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n;
int a[N+5];
int x,y;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n/2;i++) x+=a[i];
    for (int i=n/2+1;i<=n;i++) y+=a[i];
    cout<<y-x;
}

