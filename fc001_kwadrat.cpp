#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,ans=1,ans1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ans1=n;
    for (ll i=2;i<=sqrt(n);i++)
        if (n%i==0){
            ll d=0;
            while (n%i==0){
                n/=i;
                d++;
            }
            if (d%2==1) ans*=i;
        }
    if (n>1) ans*=n;
    cout<<ans*ans1;
}

