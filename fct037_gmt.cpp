#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll h,m,a,b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>m>>a>>b;
    cout<<(h-a+b+24)%24<<" "<<m;
}

