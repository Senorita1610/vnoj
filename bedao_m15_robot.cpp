#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,a=0,b=0,c=0,d=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>n>>s;
    if (n%2!=0){
        cout<<-1;
        return 0;
    }
    for (ll i=0;i<s.size();i++)
        if (s[i]=='L') a++;
        else if (s[i]=='R') b++;
        else if (s[i]=='U') c++;
        else if (s[i]=='D') d++;
    cout<<(abs(a-b)+abs(c-d))/2;
}

