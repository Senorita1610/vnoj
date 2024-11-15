#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    (n%6==0) ? cout<<n/6<<" "<<n*6 : cout<<n/6+7-(n%6)<<" "<<n*6;
}

