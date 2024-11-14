#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,c,d,x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>d;
    x=a+b-c;
    (x<d && a>=c && b>=c) ? cout<<d-x : cout<<-1;
}

