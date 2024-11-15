#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,s,a[N];
string t="0";
string cong(string a, string b){
    while (a.size()<b.size()) a='0'+a;
    while (a.size()>b.size()) b='0'+b;
    string c=a;
    ll nho=0;
    for (ll i=a.size()-1;i>=0;i--){
        ll kq=int(a[i])+int(b[i])-96+nho;
        nho=kq/10;
        c[i]=char(kq%10+48);

    }
    return (nho==0) ? c : '1'+c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        ll j=s/a[i];
        if (j*a[i]==s) j--;
        if (j>0){
            ll z=a[i]*(j+1)*j/2;
            ostringstream d;
            d<<z;
            t=cong(t,d.str());
        }
    }
    cout<<t;
}

