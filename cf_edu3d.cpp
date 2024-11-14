#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
#define no do { cout << "No" << endl; return; } while(0)
#define yes do { cout << "Yes" << endl; return; } while (0)
#define lowbit(x) ((x) & -(x))

using namespace std;

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

template<typename T> ostream & operator << (ostream &out,const set<T>&obj){out<<"set(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<*it;out<<")";return out;}
template<typename T1,typename T2> ostream & operator << (ostream &out,const map<T1,T2>&obj){out<<"map(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<it->first<<": "<<it->second;out<<")";return out;}
template<typename T1,typename T2> ostream & operator << (ostream &out,const pair<T1,T2>&obj){out<<"<"<<obj.first<<", "<<obj.second<<">";return out;}
template<typename T> ostream & operator << (ostream &out,const vector<T>&obj){out<<"vector(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<*it;out<<")";return out;}


namespace Fast_IO{ 
    const int MAXL((1 << 18) + 1);int iof, iotp;
    char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL],*iooS=ioof,*iooT=ioof+MAXL-1,ioc,iost[55];
    char Getchar(){
        if (ioiS == ioiT){
            ioiS=ioif;ioiT=ioiS+fread(ioif,1,MAXL,stdin);return (ioiS == ioiT ? EOF : *ioiS++);
        }else return (*ioiS++);
    }
    void Write(){fwrite(ioof,1,iooS-ioof,stdout);iooS=ioof;}
    void Putchar(char x){*iooS++ = x;if (iooS == iooT)Write();}
    inline int read(){
        int x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
        if(ioc==EOF)Write(),exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    inline long long read_ll(){
        long long x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
        if(ioc==EOF)Write(),exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    void Getstr(char *s, int &l){
        for(ioc=Getchar();ioc==' '||ioc=='\n'||ioc=='\t';)ioc=Getchar();
        if(ioc==EOF)Write(),exit(0);
        for(l=0;!(ioc==' '||ioc=='\n'||ioc=='\t'||ioc==EOF);ioc=Getchar())s[l++]=ioc;s[l] = 0;
    }
    template <class Int>void Print(Int x, char ch = '\0'){
        if(!x)Putchar('0');if(x<0)Putchar('-'),x=-x;while(x)iost[++iotp]=x%10+'0',x/=10;
        while(iotp)Putchar(iost[iotp--]);if (ch)Putchar(ch);
    }
    void Putstr(const char *s){for(int i=0,n=strlen(s);i<n;++i)Putchar(s[i]);}
} // namespace Fast_IO
using namespace Fast_IO;

void solve() {
    int n, m, k, s;
    n = read(), m = read(), k = read(), s = read();
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    vector<pair<int, int>> l, r;
    for (int i = 1; i <= m; i++) {
        int t, c;
        t = read(), c = read();
        if (t == 1) l.push_back({c, i});
        else r.push_back({c, i});
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    auto check = [&](int mid) -> int {
        int min_a = *min_element(a.begin() + 1, a.begin() + mid + 1);
        int min_b = *min_element(b.begin() + 1, b.begin() + mid + 1);
        //out2(min_a, min_b);
        ll cost = 0;
        int cnt = 0, pos = -1;
        for (int i = 0; i < k && i < r.size(); i++) {
            cnt++, pos = i;
            cost += 1LL * r[i].first * min_b;
        }
        ll mincost = inf;
        int minidx = -1;
        for (int i = 0; i <= k; i++) {
            if (cnt == k) {
                if (cost < mincost) {
                    mincost = cost;
                    minidx = i;
                }
            }
            if (i < l.size()) {
                cost += 1LL * l[i].first * min_a;
                cnt++;
            }
            if (cnt > k && pos >= 0) cost -= 1LL * r[pos--].first * min_b, cnt--;
        }
        //out2(mincost, minidx);
        if (mincost > s) minidx = -1;
        return minidx;
    };
    int left = 1, right = n, ans = -1, anspoint = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int point = check(mid);
        if (point != -1) {
            ans = mid;
            anspoint = point;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    Print(ans, '\n');
    if (ans != -1) {
        int idxl = 1, idxr = 1;
        for (int i = 2; i <= ans; i++) {
            if (a[idxl] > a[i]) idxl = i;
            if (b[idxr] > b[i]) idxr = i;
        }
        for (int i = 0; i < anspoint; i++) {
            Print(l[i].second, ' ');
            Print(idxl, '\n');
        }
        for (int i = 0; i < k - anspoint; i++) {
            Print(r[i].second, ' ');
            Print(idxr, '\n');
        }
    }
    Write();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
	//cin >> t;
    
    while (t--) {
    	solve(); 
	}
}

