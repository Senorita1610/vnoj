#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,d=1,ans=0,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (ll i=2;i<=n;i++)
        if (a[i]==a[i-1]) d++;
        else{
            if (d==1){
                cout<<-1;
                return 0;
            }
            else{
                ans+=(d+(3-d%3)%3)/3;
                d=1;
            }
        }
    if (d==1) cout<<-1;
    else cout<<ans+(d+(3-d%3)%3)/3;
}

