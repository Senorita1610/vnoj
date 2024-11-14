#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t;
double a,b,x,s;
void Solve(){
    cin>>a>>b>>s>>x;
    double t=s/(a+b)*x;
    cout<<(ll)t<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while (t--) Solve();
}

