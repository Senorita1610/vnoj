#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll z=1e9+7;
ll n,a[55];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (ll i=1;i<n;i++)
        if (a[i+1]-a[i]>1){
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
}

