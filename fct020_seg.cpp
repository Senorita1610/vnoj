#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=500000;
string s;
ll ans=0,d=0,o,a[N+5]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=0;i<s.size();i++){
        if (s[i]=='<'){
            d=0;
            a[i+1]=a[i]+1;
        }
        else{
            if (i==0 || s[i-1]=='<') o=a[i];
            o--;
            d++;
            a[i+1]=0;
            ans+=d-1+(o<0);
        }
        ans+=a[i+1];
    }
    cout<<ans;
}

