#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD=33;
string s,ans1="",t;
ll n,check,x=0,y=1,ans=0,mp[MOD+5]={};
vector <pair<ll,ll>> v;
bool comp(const pair <ll,ll> a, const pair <ll,ll> b){
    return a.second-a.first>b.second-b.first;
}
void Solve1(){
    mp[0]=1;
    for (ll i=s.size()-1;i>=0;i--){
        x=(x+(int(s[i])-48)*y)%MOD;
        y=(y*10)%MOD;
        ans+=mp[x];
        mp[x]++;
    }
    cout<<ans;
}
void Solve2(){
    mp[0]=s.size();
    for (ll i=s.size()-1;i>=0;i--){
        x=(x+(int(s[i])-48)*y)%MOD;
        y=(y*10)%MOD;
        if (mp[x]) v.emplace_back(i,mp[x]-1);
        if (!mp[x]) mp[x]=i;
    }
    sort(v.begin(),v.end(),comp);
    while (v.back().second-v.back().first<v[0].second-v[0].first) v.pop_back();
    for (ll i=v[0].first;i<=v[0].second;i++) ans1+=s[i];
    for (ll i=0;i<v.size();i++){
        t="";
        check=1;
        for (ll j=v[i].first;j<=v[i].second;j++){
            t+=s[j];
            if (t[t.size()-1]<ans1[t.size()-1] && check==1) goto End;
            else if (t[t.size()-1]>ans1[t.size()-1]) check=0;
        }
        ans1=t;
        End:;
    }
    cout<<ans1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>n;
    if (n==1) Solve1();
    else Solve2();
}

