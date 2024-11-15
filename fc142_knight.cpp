#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll x,y,a,b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x>>y>>a>>b;
    ((abs(x-a)==1 && abs(y-b)==2) || (abs(x-a)==2 && abs(y-b)==1)) ? cout<<"Yes" : cout<<"No";
}

