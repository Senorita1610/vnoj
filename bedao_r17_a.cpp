#include<bits/stdc++.h>
using namespace std;
long long l,r,n,m,res=1;
int main() {
    cin>>l>>r;
    m=n=r/l;
    for (long long i=2;i*i<=m;i++) {
        while (n%i==0) {
            n/=i;
            res++;
        }
    }
    if (n!=1) res++;
    cout<<res;
}

