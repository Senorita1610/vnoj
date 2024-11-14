#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long res,n,m,temp,c1[22],c2[22];
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>temp;
        for (int bit=0;bit<=19;bit++) {
            if (temp>>bit&1) c1[bit]++;
        }
    }
    for (int i=1;i<=m;i++) {
        cin>>temp;
        temp=~temp;
        for (int bit=0;bit<=19;bit++) {
            if (temp>>bit&1) c2[bit]++;
        }
    }
    for (int bit=0;bit<=19;bit++) res+=c1[bit]*c2[bit]*(1<<bit);
    cout<<res;
}

