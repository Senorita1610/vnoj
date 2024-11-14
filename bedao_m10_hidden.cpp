#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll T=32005;
ll t,a,b,s=1,x[T]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>t;
    b=t;
    if (t%a!=0){
        cout<<-1;
        return 0;
    }
    for (ll i=2;i<=sqrt(t);i++)
        while (t%i==0){
            t/=i;
            x[i]++;
        }
    for (ll i=2;i<T;i++)
        if (x[i]>0){
            for (ll j=1;j<=x[i];j++) s*=i;
            cout<<s<<" "<<b/s;
            return 0;
        }
    cout<<-1;
}

