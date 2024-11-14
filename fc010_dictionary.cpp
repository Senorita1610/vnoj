#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e4 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct TRIE {
    int NXT[MAXN * 40][26];
    int t = 0;
    void insert(const string &s) {
        int u = 0;
        for (auto c : s) {
            int i = c - 'a';
            if (NXT[u][i] == 0)
                NXT[u][i] = ++t;
            u = NXT[u][i];
        }
    }
};



int N;
string A[MAXN];
TRIE t, tr;

int TOT_CNT;
int CNT[26];
void count(int u = 0) {
    TOT_CNT += u > 0;
    FOR(i, 0, 26) {
        if (tr.NXT[u][i] > 0) {
            CNT[i] += u > 0;
            count(tr.NXT[u][i]);
        }
    }
}


ll f(int u = 0) {
    ll ret = (u > 0 ? TOT_CNT : 0);
    FOR(i, 0, 26) {
        if (t.NXT[u][i]) {
            ret -= (u > 0 ? CNT[i] : 0);
            ret += f(t.NXT[u][i]);
        }
    }
    return ret;
}

bool FND[26];
int main() {
    ri(N);
    int aux = 0;
    FOR(i, 0, N) cin >> A[i];
    FOR(i, 0, N) {
        t.insert(A[i]);
        reverse(ALL(A[i]));
        tr.insert(A[i]);
        if (A[i].size() == 1){
            int j = A[i][0] - 'a';
            aux += FND[j] ^ 1;
            FND[j] = 1;
        }
    }
    count();
    printf("%lld\n", f() + aux);
    return 0;
}

