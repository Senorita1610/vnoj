#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define runfast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e6+5;
const ll mo=1e9+7;

int main(){
  
    freopen("MATMA.INP","r",stdin); 
    freopen("MATMA.OUT","w",stdout); 
  runfast;
  string s;
  cin >> s;
  ll n=0;
  n = s.size();
  s=' '+s;
  ll t=0;
  bool kt=false;
  for(long i=1; i<=n; i++){
     if (s[i]=='0')
        kt = true;
     t += s[i] - '0';
  }
  sort(s.begin(),s.end(),greater<char>());
  if (t%3==0&&kt)
    cout << s; else
    cout << -1;
  return 0;
}

