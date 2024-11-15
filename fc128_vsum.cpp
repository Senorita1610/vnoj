#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,a[101],a1=0,a2=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a[0]=0;
    for (ll i=1;i<=100;i++) a[i]=a[i-1]+i;
    for (ll i=n;i<=100;i++)
        if ((a[i]-a[i-n])%2==0) a1=1;
        else if ((a[i]-a[i-n])%2==1) a2=1;
    if (a1==1 && a2==1) cout<<2;
    else if (a1==1) cout<<0;
    else cout<<1;
}

