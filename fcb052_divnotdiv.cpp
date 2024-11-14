#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,a,b,n;
void Solve(){
    cin>>a>>b>>n;
    if (a%b==0){
        cout<<-1<<endl;
        return;
    }
    ((n+a*(n%b!=0)-n%a)%b!=0) ? cout<<n+a*(n%a!=0)-n%a<<endl : cout<<n+a*(n%a!=0)+a-n%a<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

