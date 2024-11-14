#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s[10];
unordered_map <char,ll> mp;
bool comp(const string a, const string b){
    return mp[a[0]]<mp[b[0]];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mp['A']=1;mp['2']=2;mp['3']=3;mp['4']=4;mp['5']=5;mp['6']=6;mp['7']=7;mp['8']=8;mp['9']=9;mp['T']=10;mp['J']=11;mp['Q']=12;mp['K']=13;
    for (ll i=1;i<=5;i++) cin>>s[i];
    sort(s+1,s+6,comp);
    if (s[1][1]==s[2][1] && s[2][1]==s[3][1] && s[3][1]==s[4][1] && s[4][1]==s[5][1] && (mp[s[2][0]]+1==mp[s[3][0]] && mp[s[3][0]]+1==mp[s[4][0]] && ((mp[s[1][0]]+1==mp[s[2][0]] && mp[s[4][0]]+1==mp[s[5][0]]) || (s[5][0]=='K' && s[1][0]=='A')))) cout<<"Thung pha sanh";
    else if (s[1][0]==s[4][0] || s[2][0]==s[5][0]) cout<<"Tu quy";
    else if ((s[1][0]==s[2][0] && s[3][0]==s[5][0]) || (s[1][0]==s[3][0] && s[4][0]==s[5][0])) cout<<"Cu lu";
    else if (s[1][1]==s[2][1] && s[2][1]==s[3][1] && s[3][1]==s[4][1] && s[4][1]==s[5][1]) cout<<"Thung";
    else if (mp[s[2][0]]+1==mp[s[3][0]] && mp[s[3][0]]+1==mp[s[4][0]] && ((mp[s[1][0]]+1==mp[s[2][0]] && mp[s[4][0]]+1==mp[s[5][0]]) || (s[5][0]=='K' && s[1][0]=='A'))) cout<<"Sanh";
    else if (s[1][0]==s[3][0] || s[2][0]==s[4][0] || s[3][0]==s[5][0]) cout<<"Sam";
    else if ((s[1][0]==s[2][0] && s[3][0]==s[4][0]) || (s[1][0]==s[2][0] && s[3][0]==s[5][0]) || (s[1][0]==s[2][0] && s[4][0]==s[5][0]) || (s[1][0]==s[3][0] && s[4][0]==s[5][0]) || (s[2][0]==s[3][0] && s[4][0]==s[5][0])) cout<<"Thu";
    else if (s[1][0]==s[2][0] || s[2][0]==s[3][0] || s[3][0]==s[4][0] || s[4][0]==s[5][0]) cout<<"Doi";
    else cout<<"Mau thau";
}

