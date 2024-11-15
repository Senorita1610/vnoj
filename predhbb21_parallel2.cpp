#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,a,b;
void Solve(){
    cin>>a>>b;
    ((a<=2 && b<=1) || (a<=1 && b<=2)) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

