#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll n,ans=0,d=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    for (ll i=0;i<s.size()-2;i++)
        if (s[i]=='a'){
            for (ll j=i+1;j<s.size();j++)
                if (s[j]!=s[j-1]) d++;
                else break;
            if (d%2==0) d--;
            ans=max(ans,d);
            i+=(d-1);
            d=1;
        }
    for (ll i=1;i<=ans;i++)
        (i%2==1) ? cout<<'a' : cout<<'b';
}

