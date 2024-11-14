// Template //
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <array>
#include <cassert>
#include <random>

#define FOR(i, a, b) for (ll i = a, _b = b; i <= _b; i++)
#define FORD(i, a, b) for (ll i = a, _b = b; i >= _b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//

int n,d;
int a[maxn];
vector<pair<int,ii>> v; 
void input()
{
    cin>>n>>d;
    FOR(i,1,n)
        cin>>a[i];
}


vector <int> val;
bool cnt[maxn];
void lds_go_goooo()
{
    FOR(i,1,n)
        FOR(j,i+1,n)
            if(a[i]>a[j])
                v.pb({a[i]+a[j],{j,i}});
            else
                v.pb({a[i]+a[j],{i,j}});
    
    sort(ALL(v));
    int res=0;
    FOR(i,0,v.size()-1)
    {
        int ans=0;
        int j=i;
        vector<ii> p;
        while(j<=v.size()-1 && v[j].fi-v[i].fi<=d)
        {
            p.pb(v[j].se);
            j++;
        }
        sort(ALL(p),[](ii i,ii j)
        {
            if(a[i.fi]==a[j.fi])
                return a[i.se]>a[j.se];
            return a[i.fi]<a[j.fi];
        });
        for(auto [u,v]: p)
        {
            if(cnt[u]==0&&cnt[v]==0)
            {
                cnt[u]=1;
                cnt[v]=1;
                ans++;
            }
        }
        for(auto [u,v]: p)
            cnt[u]=cnt[v]=0;
        while(v[i].fi==v[i+1].fi)
            i++;
        res=max(res,ans);
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "PAIR"
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    // int sub=1;
    // cin>>sub;
    ll test_case = 1; // cin>>test_case;
    while (test_case--)
    {
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}

