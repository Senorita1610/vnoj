#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <queue>
#define ll long long 
#define x first
#define y second
using namespace std;
const int maxN = 100001;
const int inf  = 2000000001;
int a[maxN], f[maxN];
int N, ans;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    f[1] = 1;
    ans = 1;
    for (int i = 2; i <= N; i++)
        if (a[i] < a[f[ans]]) f[++ans] = i;
        else {
            int L = 1, R = ans;
            while (L < R) {
                int mid = (L + R) >> 1;
                if (a[f[mid]] > a[i]) L = mid + 1; else R = mid;
            }
            f[L] = i;
        }
    cout << ans;
    return 0;
}

