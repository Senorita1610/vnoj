#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x,y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    x=1,y=n;
    while (x<y){
        cout<<x<<" "<<y<<" ";
        x++;
        y--;
    }
    if (x==y) cout<<x;
}

