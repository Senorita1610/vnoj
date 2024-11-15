#include <bits/stdc++.h>
#define ll long long int

using namespace std;

char a,b;
char kt(ll a, ll b){
    if (a==b) return 'D';
    if (a=='S' && b=='R') return 'B';
    if (a=='S' && b=='P') return 'A';
    if (a=='R' && b=='P') return 'B';
    if (a=='R' && b=='S') return 'A';
    if (a=='P' && b=='S') return 'B';
    if (a=='P' && b=='R') return 'A';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    cout<<kt(a,b);
}

