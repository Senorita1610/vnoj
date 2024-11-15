#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,c,d;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>d;
    (max(max(a,b),c)-min(min(a,b),c)<=d) ? cout<<"Yes" : cout<<"No";
}

