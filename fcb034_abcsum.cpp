#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,c;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c;
    (max(a,max(b,c))*2==a+b+c) ? cout<<1 : cout<<0;
}

