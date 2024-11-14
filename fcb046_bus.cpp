#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m,p,x,y;
vector <ll> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>p;
    while (n--){
        cin>>x>>y;
        v.push_back(y-x+1);
    }
    sort(v.begin(),v.end());
    cout<<v[m-1];
}

