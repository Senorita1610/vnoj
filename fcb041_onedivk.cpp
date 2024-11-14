#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,s=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        s=(s*10+1)%n;
        if (s==0){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}

