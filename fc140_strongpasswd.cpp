#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll a=0,b=0,c=0,d=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline (cin,s);
    if (s.size()<8){
        cout<<"NO";
        return 0;
    }
    for (ll i=0;i<s.size();i++){
        if (s[i]>='A' && s[i]<='Z') a++;
        else if (s[i]>='a' && s[i]<='z') b++;
        else if (s[i]>='0' && s[i]<='9') c++;
        else d++;
        if (i!=0 && s[i]==s[i-1]){
            cout<<"NO";
            return 0;
        }
    }
    if (a==0 || b==0 || c==0 || d==0) cout<<"NO";
    else cout<<"YES";
}

