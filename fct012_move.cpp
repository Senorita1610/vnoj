#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>a>>b>>c>>d;
    ((a-c)%2!=0 || (b-d)%2!=0) ? cout<<-1 : cout<<(abs(a-c))/2+(abs(b-d))/2;
}

