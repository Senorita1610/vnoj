#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n;
void Solve(){
    ll ans=0;
    cin>>n;
    while (n>1){
        if (n%3!=0){
            cout<<-1<<endl;
            return;
        }
        (n%2==0) ? n/=6 : n*=2;
        ans++;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

