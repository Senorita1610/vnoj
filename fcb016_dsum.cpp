#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cout<<n/100+n%10+(n%100)/10;
}

