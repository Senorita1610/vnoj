#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,a[N],d=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (ll i=2;i<=n;i++)
        if (a[i]==a[i-1]) d++;
        else{
            if (d%2==1){
                cout<<a[i-1];
                return 0;
            }
            d=1;
        }
    if (d%2==1) cout<<a[n];
}

