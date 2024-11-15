#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    x=sqrt(n*2);
    (x*(x+1)/2==n) ? cout<<"Yes." : cout<<"No.";
}

