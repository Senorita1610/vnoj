#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll n,a=0,b=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>s;
        (s=="Vietnam") ? a++ : b++;
    }
    cout<<a<<" "<<b;
}

