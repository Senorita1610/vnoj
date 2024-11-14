#include <bits/stdc++.h>
using namespace std; 
typedef pair<int,int> ii;
typedef long long ll; 
typedef long double ld;
typedef unsigned long long llu;
#define X  first
#define Y  second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)
#define EL printf("\n")
#define debug 1
const double pi = acos(-1.0);
string a, b, s;
vector<int> Z_Function(string s) {
    vector<int> z(s.size(),0);
    for(int i=1,l=0,r=0;i<s.size();i++) {
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i+z[i] < s.size() && s[i+z[i]] == s[z[i]]) ++z[i];
        if (i+z[i]-1 > r) l = i, r = i+z[i]-1;
    }
    return z;
}

int main() {
    cin >> a >> b;
    s = b + '#' + a;
    vector<int> z = Z_Function(s);
    int ans = 0;
    FOR(i,b.size()+1,s.size()-1) {
        if (ans < z[i] && i+z[i] == s.size()) ans = z[i];
    }
    FOR(i,0,a.size()-1) printf("%c", a[i]);
    FOR(i,ans,b.size()-1) printf("%c", b[i]);
    EL;
    return 0;
}

