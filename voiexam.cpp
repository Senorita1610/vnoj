#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

string str[][9] = { {"1*2"},
                    {"(1*2)*3", "1*(2*3)"},
                    {"(1*2)*(3*4)","((1*2)*3)*4","(1*(2*3))*4","1*((2*3)*4)","1*(2*(3*4))"}
                  };
int sz[] = {1,2,5};

vector <int> val;
vector <char> sign;

long long calc(long long a, long long b, char c) {
    if (c == '-') return a - b;
    else if (c == '+') return a + b;
    else return a * b;
}

long long rpn(string s) {
    s = '(' + s; s += ')';
    stack < long long > stv;
    stack < char > stc;
    int numSign = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') stc.push(s[i]);
        else if (s[i] == ')') {
            if (!stc.empty() && stc.top() != '(') {
                long long v1 = stv.top(); stv.pop();
                long long v2 = stv.top(); stv.pop();
                long long v = calc(v2, v1, stc.top()); stc.pop();
                stv.push(v);
            }
            if (!stc.empty() && stc.top() == '(') stc.pop();
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            stv.push(val[s[i]-'1']);
        }
        else stc.push(sign[++numSign]);
    }
    return stv.top();
}

string build(string s) {
    int numSign = -1;
    string res = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == ')') res += s[i];
        else if (s[i] >= '0' && s[i] <= '9') {
            int v = val[s[i]-'1'];
            string number = "";
            if (v == 0) number = "0";
            else { while(v) number += (char)(v % 10 + '0'), v /= 10; reverse(number.begin(), number.end()); }
            res += number;
        }
        else res += sign[++numSign];
    }
    return res;
}

const int N = 2010;
map <long long, string> mp[N];
vector <long long> all;
vector <int> G[N];
int n;

void solve(string s, int pos) {
    int v = 0; bool in = 0; val.clear(); sign.clear();
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') v = 10 * v + s[i] - '0', in = 1;
        else {
            sign.push_back(s[i]);
            if (in) val.push_back(v), v = 0, in = 0;
        }
    }
    if (in) val.push_back(v);
    // gen
    int num = val.size();
    for (int i = 0; i < sz[num-2]; ++i) {
        long long res = rpn(str[num-2][i]);
        mp[pos][res] = build(str[num-2][i]);
        //cerr << build(str[num-2][i]) << ' ' << res << endl;
        all.push_back(res);
    }
}

// Matching
vector <int> mx, my, check;

bool dfs(int u) {
    if (u == 0) return 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!check[v]) {
            check[v] = 1;
            if (dfs(my[v])) { my[v] = u; mx[u] = v; return 1; }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        solve(s, i);
    }

    sort(all.begin(), all.end());
    all.resize(distance(all.begin(), unique(all.begin(), all.end())));

    for (int i = 1; i <= n; ++i) {
        for (map <long long, string>::iterator it = mp[i].begin(); it != mp[i].end(); ++it) {
            long long cur = (it->first);
            G[i].push_back(lower_bound(all.begin(), all.end(), cur) - all.begin() + 1);
        }
    }


    int C = n, C_ = n + 1, m = all.size();
    mx.assign(n + 1, 0); my.assign(m + 1, 0);
    while(C && C < C_) {
        C_ = C; check.assign(m + 1, 0);
        for (int i = 1; i <= n; ++i) if (!mx[i]) C -= dfs(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) if (mx[i]) ++ans;
    if (ans != n) cout << "NO SOLUTION" << endl;
    else {
        for (int i = 1; i <= n; ++i) {
            long long v = all[mx[i]-1];
            cout << mp[i][v] << endl;
        }
    }

}

