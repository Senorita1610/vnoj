#include<bits/stdc++.h>
#define int long long
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
using namespace std;
string s,t;
map<char,int> mp;
int n;
bool isPalindrome(string s){
    forUp(i,1,n/2,1){
        if(s[i]!=s[n-i+1]) return false;
    }
    return true;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    s=" "+s;
    if(!isPalindrome(s)) cout<<n;
    else{
        forUp(i,1,n,1) mp[s[i]]++;
        if(mp.size()==1) cout << 0;
        else cout<<n-1;
    }
}

