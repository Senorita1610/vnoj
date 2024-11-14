#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000005;
ll n,o,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    o=a[2]-a[1];
    for (ll i=2;i<=n;i++)
        if (a[i]-a[i-1]!=o){
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
}

