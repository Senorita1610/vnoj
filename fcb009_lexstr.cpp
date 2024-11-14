#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005;
ll n,a[30],b[30]={},d=1;
char s[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>s[i];
        if (s[i]>='a' && s[i]<='z') b[int(s[i])-96]++;
    }
    for (ll i=1;i<=26;i++){
        cin>>a[i];
        if (a[i]<b[i]){
            cout<<-1;
            return 0;
        }
        else a[i]-=b[i];
    }
    for (ll i=1;i<=n;i++)
        if (s[i]>='a' && s[i]<='z') cout<<s[i];
        else{
            while (a[d]==0) d++;
            cout<<char(d+96);
            a[d]--;
        }
}

