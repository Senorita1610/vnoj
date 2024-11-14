#include                    <bits/stdc++.h>
using namespace             std;
#define fu(i, a, b)         for (int i = a; i<=b; i++)
#define fd(i, a, b)         for (int i = a; i>=b; i--)
#define fa(it, arr)			for (auto it : arr)
#define tri(a, b, c)        ((a) ? (b) : (c))
#define carr(arr, n)        cout<<"[";fu(i, 1, n ){cout<<arr[i]<<tri(i == n, "", ", ");}cout<<"]\n";
#define fi                  first
#define se                  second
#define all(it)             it.fi << " " << it.se <<"\n"
#define debug(x)            cerr<<"+Debug for "<<(#x)<<" : "<<x<<"\n";
#define comma(f, x)			fixed << setprecision((x)) << f
#define endl				cout<<"\n";
typedef pair<int, int>      ii;
typedef long long           ll;
typedef vector<int>         vi;
typedef vector<ii>          vii;
typedef vector<ll>          vll;
const int maxN =            3e5;
const int mod =             1e9 + 7;
const int inf =             INT_MAX;
const double PI =           3.14159265358979;
const auto INP_FILE =		"sample.inp";
const auto OUT_FILE =		"sample.out";
void IO(short choice){      if (choice == 1) freopen(INP_FILE, "r", stdin);
else						if (choice == 2){freopen(INP_FILE, "r", stdin); freopen(OUT_FILE, "w", stdout);}
else						if (choice == 3) ios::sync_with_stdio(false);cin.tie(nullptr);}
map<string, int> m;
string str[30] = {"Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra",
    "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};
pair<ii, ii> p[30];
void update(int i, int a, int b, int c, int d){
    p[i].fi.fi = a;
    p[i].fi.se = b;
    p[i].se.fi = c;
    p[i].se.se = d;
}
bool legit(int i, int x, int y){
    int a = p[i].fi.fi;
    int b = p[i].fi.se;
    int c = p[i].se.fi;
    int d = p[i].se.se;
    if (y == b){
        if (x >= a) return 1;
    }
    if (y == d){
        if (x <= c) return 1;
    }
    return 0;
}

string find_AS(int d, int x){
    for (int i = 1; i<=12; i++){
        if (legit(i, d, x)) return str[i-1];
    }
    return " ";
}

signed main(){
    IO(3);
    m["Jan"] = 1;
    m["Feb"] = 2;
    m["Mar"] = 3;
    m["Apr"] = 4;
    m["May"] = 5;
    m["Jun"] = 6;
    m["Jul"] = 7;
    m["Aug"] = 8;
    m["Sep"] = 9;
    m["Oct"] = 10;
    m["Nov"] = 11;
    m["Dec"] = 12;
    
    update(1, 21, 3, 20, 4);
    update(2, 21, 4, 20, 5);
    update(3, 21, 5, 21, 6);
    update(4, 22, 6, 22, 7);
    update(5, 23, 7, 22, 8);
    update(6, 23, 8, 21, 9);
    update(7, 22, 9, 22, 10);
    update(8, 23, 10, 22, 11);
    update(9, 23, 11, 21, 12);
    update(10, 22, 12, 20, 1);
    update(11, 21, 1, 19, 2);
    update(12, 20, 2, 20, 3);

    int T;
    cin>>T;
    while (T--){
        int n;
        string s;
        cin>>n>>s;
        cout<<find_AS(n, m[s]);
        endl;
    }
}

