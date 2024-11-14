#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000005;
ll n,o,a[N],x[N],y[N],ans=0,ans1=0;
stack <ll> st;
struct Node{
    ll a,b;
};
Node s[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    s[0].a=0;s[n+1].b=0;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        s[i].a=max(s[i-1].a,a[i]);
        while (!st.empty() && a[st.top()]<=a[i]) st.pop();
        x[i]=(st.empty()) ? 0 : st.top();
        st.push(i);
    }
    st=stack <ll> {};
    for (ll i=n;i>=1;i--){
        s[i].b=max(s[i+1].b,a[i]);
        while (!st.empty() && a[st.top()]<=a[i]) st.pop();
        y[i]=(st.empty()) ? 0 : st.top();
        st.push(i);
    }
    for (ll i=1;i<=n;i++)
        ans+=(min(s[i].a,s[i].b)-a[i]);
    for (ll i=1;i<=n;i++)
        if ((x[i]==0 && y[i]==0) || (x[i]!=0 && y[i]!=0));
        else{
            if (x[i]!=0) o=i-x[i]-1;
            else if (y[i]!=0) o=y[i]-i-1;
            ans1=max(ans1,o);
        }
    cout<<ans+ans1;
}

