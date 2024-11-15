#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
char a[10];
ll b[10]={};
set <string> st;
void Check(){
    string t="";
    for (ll i=0;i<s.size();i++) t+=a[i];
    st.insert(t);
}
void Try(ll i){
    for (ll j=0;j<s.size();j++)
        if (b[j]==0){
            a[i]=s[j];
            b[j]=1;
            if (i<s.size()-1) Try(i+1);
            else Check();
            b[j]=0;
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    Try(0);
    cout<<st.size()<<endl;
    for (auto x : st) cout<<x<<endl;
}

