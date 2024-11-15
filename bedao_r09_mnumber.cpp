#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x;
    if (x%2==1 && x>1) cout<<"YES"<<endl<<(x+1)/2<<" "<<(x-1)/2<<endl;
    else if (x%4==0) cout<<"YES"<<endl<<x/4-1<<" "<<x/4+1<<endl;
    else cout<<"NO"<<endl;
}

