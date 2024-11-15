#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,c,x[100]={},ans=0,m=0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b>>c;
	for (ll i=1;i<=a;i++)
        for (ll j=1;j<=b;j++)
            for (ll z=1;z<=c;z++)
                x[i+j+z]++;
    for (ll i=1;i<=a+b+c;i++)
        if (x[i]>m){
            m=x[i];
            ans=i;
        }
    cout<<ans;
}

