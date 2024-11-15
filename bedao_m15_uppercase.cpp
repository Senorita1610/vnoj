#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline (cin,s);
    for (ll i=0;i<s.size();i++)
        if (i==0 && s[i]>='a' && s[i]<='z') cout<<char(s[i]-32);
        else if (s[i]>='a' && s[i]<='z' && s[i-1]==' ') cout<<char(s[i]-32);
        else if (s[i]!=' ') cout<<s[i];
}

