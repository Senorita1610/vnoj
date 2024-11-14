#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100;
ll n,m,q;
string s;
char a[N+5][N+5];
ll Check(){
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            if (a[i][j]==s[0]){
                if (i>=s.size()){
                    for (ll k=0;k<s.size();k++)
                        if (s[k]!=a[i-k][j]) goto Next1;
                    return 1;
                    Next1:;
                }
                if (j>=s.size()){
                    for (ll k=0;k<s.size();k++)
                        if (s[k]!=a[i][j-k]) goto Next2;
                    return 1;
                    Next2:;
                }
                if (i<=n-s.size()+1){
                    for (ll k=0;k<s.size();k++)
                        if (s[k]!=a[i+k][j]) goto Next3;
                    return 1;
                    Next3:;
                }
                if (j<=m-s.size()+1){
                    for (ll k=0;k<s.size();k++)
                        if (s[k]!=a[i][j+k]) goto Next4;
                    return 1;
                    Next4:;
                }
                if (i>=s.size() && j>=s.size()){
                    for (ll k=0;k<s.size();k++)
                        if (s[k]!=a[i-k][j-k]) goto Next5;
                    return 1;
                    Next5:;
                }
                if (i>=s.size() && j<=m-s.size()+1){
                    for (ll k=0;k<s.size();k++)
                        if (s[k]!=a[i-k][j+k]) goto Next6;
                    return 1;
                    Next6:;
                }
                if (i<=n-s.size()+1 && j<=m-s.size()+1){
                    for (ll k=0;k<s.size();k++)
                        if (s[k]!=a[i+k][j+k]) goto Next7;
                    return 1;
                    Next7:;
                }
                if (i<=n-s.size()+1 && j>=s.size()){
                    for (ll k=0;k<s.size();k++)
                        if (s[k]!=a[i+k][j-k]) goto Next8;
                    return 1;
                    Next8:;
                }
            }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>q;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            cin>>a[i][j];
    while (q--){
        cin>>s;
        (Check()) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}

