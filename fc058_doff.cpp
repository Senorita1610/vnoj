#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x,y;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    x=n/7*2;
    if (n%7==6) x++;
    if (n==1) y=1;
    else{
        y=2;
        n-=2;
        (n%7==6) ? y+=n/7*2+1 : y+=n/7*2;
    }
    cout<<x<<" "<<y;
}

