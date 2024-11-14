#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
char k;
stack <char> st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>k;
        if (k=='('){
            cout<<k;
            st.push(k);
        }
        else if (k==')'){
            if (st.empty() || st.top()==')') cout<<"()";
            else{
                cout<<k;
                st.pop();
            }
        }
    }
    for (ll i=1;i<=st.size();i++) cout<<')';
}

