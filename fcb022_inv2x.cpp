#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005;
ll n,s=0,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        for (ll j=1;j<i;j++)
            if (a[j]>a[i]*2) s++;
    }
    cout<<s;
}

