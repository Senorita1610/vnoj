#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,q,x,a[N],f[N];
stack <ll> st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=n;i>=1;i--){
        if (!st.empty()){
            while (st.top()<=a[i]){
                st.pop();
                if (st.empty()) break;
            }
        }
        if (st.empty()) f[i]=0;
        else f[i]=st.size();
        st.push(a[i]);
    }
    while (q--){
        cin>>x;
        cout<<f[x]<<endl;
    }
}

