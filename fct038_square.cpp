#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    for (ll i=1;i<=a;i++){
        for (ll j=1;j<=a;j++)
            if (j>a-b && i>a-b) cout<<"  ";
            else cout<<"* ";
        cout<<endl;
    }
}

