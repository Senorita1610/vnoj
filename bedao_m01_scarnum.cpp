#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--){
        cin>>n;
        (n%2!=0 && n%5!=0) ? cout<<"NO"<<endl : cout<<"YES"<<endl;
    }
}

