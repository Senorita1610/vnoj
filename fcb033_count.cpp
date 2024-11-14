#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,x;
void Solve(){
    cin>>n;
    x=n;
    for (ll i=2;i<=sqrt(x);i++)
        if (x%i==0){
            while (x%i==0) x/=i;
            n=n/i*(i-1);
        }
    if (x>1) n=n/x*(x-1);
    cout<<n<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

