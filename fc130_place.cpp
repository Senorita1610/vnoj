#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b;
ll Check(ll n){
    for (ll i=2;i<=sqrt(n);i++)
        if (n%i==0){
            if (i<=b) return 0;
            while (n%i==0) n/=i;
        }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>b>>a;
    for (ll i=a;i>b;i--)
        if (Check(i)==1){
            cout<<i;
            return 0;
        }
    cout<<-1;
}

