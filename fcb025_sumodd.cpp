#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll l,r;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>l>>r;
    if (l%2==0) l++;
    if (r%2==0) r--;
    (l>r) ? cout<<0 : cout<<(l+r)*((r-l)/2+1)/2;
}

