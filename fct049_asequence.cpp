#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000005;
ll n,a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        if (i>1 && a[i]-a[i-1]!=a[2]-a[1]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}

