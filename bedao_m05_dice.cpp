#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if (n%4==1) cout<<6;
    else if (n%4==2) cout<<4;
    else if (n%4==3) cout<<1;
    else cout<<3;
}

