#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    if (a*b>0) cout<<1;
    if (a*b==0) cout<<0;
    if (a*b<0) cout<<-1;
}

