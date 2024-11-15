#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll S=2000;
string s;
ll n,a[S+5][S+5]={},x[S+5]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=s.size()-1;i>=0;i--)
        for (ll j=0;j<s.size();j++)
            if (i>j) a[i][j]=0;
            else if (i<=j){
                if (s[i]==s[j]){
                    if (i==j) a[i][j]=1;
                    else a[i][j]=a[i+1][j-1]+2;
                }
                else if (s[i]!=s[j]){
                    if (i+1==j) a[i][j]=1;
                    else a[i][j]=max(a[i+1][j],a[i][j-1]);
                }
            }
    n=a[0][s.size()-1];
    ll i=0,j=s.size()-1;
    while (n>0){
        if (s[i]==s[j]){
            n-=2;
            x[i]=1;
            x[j]=1;
            i++;
            j--;
        }
        else if (s[i]!=s[j]){
            if (a[i+1][j]>a[i][j-1]) i++;
            else j--;
        }
    }
    for (ll i=0;i<s.size();i++)
        if (x[i]==1) cout<<s[i];
}

