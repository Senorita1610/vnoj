#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll t,x,y;
void Solve(){
    cin>>x>>y;
    x--;y--;
    while (x<y){
        if (s[x]!=s[y]){
            cout<<"NO"<<endl;
            return;
        }
        x++;
        y--;
    }
    cout<<"YES"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>t;
    while (t--) Solve();
}

