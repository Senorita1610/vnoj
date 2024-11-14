#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (ll i=1;i<=5;i++)
        for (ll j=1;j<=5;j++){
            cin>>a;
            if (a==1){
                cout<<abs(i-3)+abs(j-3);
                return 0;
            }
        }
}

