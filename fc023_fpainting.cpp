#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,c,d,x[105]={},s=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>d;
    for (ll i=a;i<=b;i++){
        if (x[i]==0) s++;
        x[i]=1;
    }
    for (ll i=c;i<=d;i++){
        if (x[i]==0) s++;
        x[i]=1;
    }
    if (c>b or a>d) s--;
    cout<<s-1;
}

