#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define X first
#define Y second
using namespace std;
int n, a[100010], f[100010], k = 0, lst[100010];

int Find(int p) {
    int l = 1, r = k, m = (l+r)>>1;
    while (l!=m && r!=m) {
        if (a[lst[m]] < a[p]) l = m;
        else r = m-1;
        m = (l+r)>>1;
    }
    REPD(i,r,l) if (a[lst[i]] < a[p]) return i;
    return 0;
}
int Find2(int p) {
    int l = 1, r = k, m = (l+r)>>1;
    while (l!=m && r!=m) {
        if (a[lst[m]] > a[p]) l = m;
        else r = m-1;
        m = (l+r)>>1;
    }
    REPD(i,r,l) if (a[lst[i]] > a[p]) return i;
    return 0;
}
void process() {
    scanf("%d",&n);
    REP(i,1,n) scanf("%d",&a[i]);
    int ans = 0, t;
    REPD(i,n,1) {
        t = Find(i);
        f[i] = t+1;
        if (t+1 > k) {
            k++; lst[k] = i;
        }
        else if (a[i] < a[lst[t+1]]) lst[t+1] = i;
    }
    k = 0;
    REPD(i,n,1) {
        t = Find2(i);
        ans = max(ans,f[i]+t);
        if (t+1 > k) {
            k++; lst[k] = i;
        }
        else if (a[i] > a[lst[t+1]]) lst[t+1] = i;
    }
    cout << ans;
}
int main(void)
{
    process();
	return 0;
}

