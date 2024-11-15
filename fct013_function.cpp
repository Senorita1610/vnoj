#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n;
    (n%2==0) ? cout<<n/2 : cout<<n/2-n;
}

