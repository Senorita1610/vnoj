#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,s=510510;
vector <ll> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=sqrt(s);i++)
        if (s%i==0){
            v.push_back(i);
            if (i*i!=s) v.push_back(s/i);
        }
    for (ll i=0;i<n;i++) cout<<v[i]<<" ";
}

