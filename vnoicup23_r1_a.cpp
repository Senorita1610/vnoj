#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105;
ll t,n,a[N];
void Solve(){
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++)
        if (a[a[a[i]]]==i){
            cout<<"<3"<<endl;
            return;
        }
    cout<<"</3"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

