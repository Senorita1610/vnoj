#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105;
ll n,x,y=0,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>x;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        y+=a[i];
    }
    sort(a+1,a+n+1);
    for (ll i=2;i<=n;i++)
        if ((a[i]-a[i-1])%x!=0){
            cout<<-1;
            return 0;
        }
    cout<<(a[n]*n-y)/x;
}

