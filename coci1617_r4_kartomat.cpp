#include <bits/stdc++.h>
#define sts stable_sort
#define B begin()
#define rB rbegin()
#define E end()
#define rE rend()
#define F first
#define S second
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define eb emplace_back
#define ll long long
#define ui unsigned int
#define ull unsigned long long
 
using namespace std;
 
const int MAXN = 1e6 + 4;
const int MOD = 1e9 + 7;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int n; cin >> n;
    vector<string> v(n);
 
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    string s; cin >> s;
    map<char, bool> m;
 
    for(int i = 0; i < n; i++){
        if(v[i].substr(0, s.size()) == s){
            m[v[i][s.size()]] = 1;
        }
    }
 
    string key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "***";
    for(int i = 0; i < key.size(); i++){
        if(m[key[i]]){
            cout << key[i];
        }else{
            cout << "*";
        }
        if(i == 4 || i == 12 || i == 20)cout << "\n";
    }cout << "***\n";
 
    return 0;
}

