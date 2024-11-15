#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x,ans=0;
stack <ll> st;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>x;
        while (!st.empty() && st.top()<x){
            mp[st.top()]--;
            st.pop();
            ans++;
        }
        if (!st.empty()){
            (st.top()==x) ? ans+=(mp[x]+(mp[x]<st.size())) : ans++;
        }
        mp[x]++;
        st.push(x);
    }
    cout<<ans;
}

