#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=sqrt(n);i>=1;i--)
        if (n%i==0){
            cout<<i+n/i-2;
            return 0;
        }
}

