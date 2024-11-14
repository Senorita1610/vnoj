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
        if (n<38) cout<<n<<endl;
        else if (n%5>=3) cout<<n-n%5+5<<endl;
        else cout<<n<<endl;
    }
}

