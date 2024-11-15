#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    while (a<=b){
        a*=3,b*=2;
        ans++;
    }
    cout<<ans;
}

