#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=505,K=30;
ll n,m,k,x,t=1,ans[N];
char a[N][K];
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k>>x>>s;
    for (ll i=1;i<=m;i++){
        char z[k+1];
        for (ll j=1;j<=k;j++) cin>>z[j];
        sort(z+1,z+k+1);
        for (ll j=1;j<=k;j++) a[i][j]=z[j];
    }
    for (ll i=1;i<=m;i++){
        ll o=1;
        if (x==0){
            ans[i]=k;
            goto End;
        }
        for (ll j=1;j<=m-i;j++)
            if (o*k<=x) o*=k;
            else{
                ans[i]=1;
                goto End;
            }
        (x%o==0) ? ans[i]=x/o : ans[i]=x/o+1;
        x%=o;
        End:;
    }

    for (ll i=0;i<n;i++)
        if (s[i]!='#') cout<<s[i];
        else{
            cout<<a[t][ans[t]];
            t++;
        }
}

