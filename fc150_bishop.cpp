#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m;
long long a[N+5][N+5];
long long c1[N*2+5],c2[N*2+5];
long long res=LLONG_MIN;
int main() {
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            c1[i+j]+=a[i][j];
            c2[i-j+N]+=a[i][j];
        }
    }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            res=max(res,c1[i+j]+c2[i-j+N]-a[i][j]);
    cout<<res;
}

