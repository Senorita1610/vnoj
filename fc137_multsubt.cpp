#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k;
vector <ll> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    while (n>1){
        if (n%k==0){
            v.push_back(1);
            n/=k;
        }
        else{
            v.push_back(2);
            n++;
        }
    }
    cout<<v.size()<<endl;
    for (auto x : v) cout<<x<<" ";
}

