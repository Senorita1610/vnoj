#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,a,b,x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>b;
    for (ll i=1;i<=n;i++){
        cin>>x;
        (x*x<=a*a+b*b) ? cout<<"DA"<<endl : cout<<"NE"<<endl;
    }
}

