#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int readInt() {
    int x=0;
    char ch=getchar_unlocked();
    bool s=1;
    while(ch<'0'||ch>'9'){if(ch=='-')s=0;ch=getchar_unlocked();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar_unlocked();}
    return s?x:-x;
}
constexpr int N = 1e6+5;
pair<int,int> a[N];
int main() {
    int n = readInt();
    for(int i = 0; i < n; i++) {
      a[i].first = readInt();
      a[i].second = readInt();
    }
    a[n].first = 0;
    a[n].second = 0;
    sort(a, a+n+1);
    long long ans = 0;
    for(int i = n - 1; i >= 0; i--) {
      a[i].second=max(a[i].second, a[i+1].second);
      ans += 1ll*(a[i+1].first-a[i].first)*a[i+1].second;
    }
    printf("%lld", ans);
    return 0;
}

