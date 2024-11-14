#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string n;
ll t,d,x,y;
void Solve(){
    d=0;
    cin>>n;
    for (ll i=0;i<n.size();i++)
        if (n[i]=='1') d++;
    if (d==0){
        cout<<-1<<endl;
        return;
    }
    for (ll i=0;i<n.size();i++)
        if (n[i]=='1'){
            x=i;
            break;
        }
    for (ll i=n.size()-1;i>=0;i--)
        if (n[i]=='1'){
            y=i;
            break;
        }
    cout<<y-x+1-d<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

