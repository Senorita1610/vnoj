#include <iostream>
#include <cstdio>
using namespace std;
const int maxN = 13;
int a[maxN], f[maxN];
int n, p;
bool fr[maxN];
int main() {
        f[0] = 1;
        for (int i = 1; i <= 12; i++) f[i] = f[i-1] * i;
        int x;
        while (cin >> x) a[++n] = x;
        p = a[n--];
        int ans = 1;
        for (int i = 1; i <= n; i++) {
                int temp = 0;
                for (int j = 1; j <= n; j++) temp += j < a[i] && !fr[j];
                ans += f[n-i] * temp;
                fr[a[i]] = true;
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++) fr[i] = false, a[i] = 0;
        p--;
        for (int i = 1; i <= n; i++) {
                int ord = 0, cnt = 0;
                while (x > f[n-i]) x -= f[n-i], ord++;
                for (int j = 1; j <= n; j++) {
                        if (!fr[j] && cnt == ord) {
                                a[i] = j;
                                fr[j] = true;
                                break;
                        }
                        if (!fr[j]) cnt++;
                }
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        return 0;
}

