#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,a;
vector <ll> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        if (!v.empty() && (v.back()+a)%2==0) v.pop_back();
        else v.push_back(a);
    }
    cout<<v.size();
}

