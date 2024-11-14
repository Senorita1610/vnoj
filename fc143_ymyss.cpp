#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    ((n-1)%(k-1)==0) ? cout<<(n-1)/(k-1) : cout<<(n-1)/(k-1)+1;
}

