#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll k,d=0,x=0,y=0,z=0,ans=inf;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>s;
    for (ll i=0;i<s.size();i++){
        if (s[i]=='V') x++;
        else if (s[i]=='C') y++;
        else if (s[i]=='A') z++;
        while (1){
            if ((s[d]=='V' && x<=k) || (s[d]=='C' && y<=k) || (s[d]=='A' && z<=k)) break;
            if (s[d]=='V') x--;
            else if (s[d]=='C') y--;
            else if (s[d]=='A') z--;
            d++;
        }
        if (x>=k && y>=k && z>=k) ans=min(ans,i-d+1-3*k);
    }
    cout<<ans*(ans!=inf)-(ans==inf);
}

