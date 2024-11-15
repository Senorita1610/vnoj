#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll A=2005;
string a,b;
ll x[A][A];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    for (ll i=0;i<A;i++){
        x[i][0]=0;
        x[0][i]=0;
    }
    for (ll i=0;i<a.size();i++)
        for (ll j=0;j<b.size();j++)
            if (a[i]==b[j]) x[i+1][j+1]=x[i][j]+1;
            else x[i+1][j+1]=max(x[i+1][j],x[i][j+1]);
    cout<<x[a.size()][b.size()];
}

