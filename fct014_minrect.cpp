#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll x,y,z,t;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x>>y>>z>>t;
    cout<<abs(x-z)*abs(y-t);
}

