#include <bits/stdc++.h>
using namespace std;
bool MB1;

const int M = 3e5 + 5;

int n, q;
struct cpp {
    int x, y;
} Fx[M], Fy[M];
bool cmpx(cpp a, cpp b) {
    if (a.x == b.x)
        return a.y < b.y;

    return a.x < b.x;
}
bool cmpy(cpp a, cpp b) {
    if (a.y == b.y)
        return a.x < b.x;

    return a.y < b.y;
}

bool MB2;
int main() {
    scanf("%d", &n);

    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y);
        Fx[i] = (cpp) {
            x, y
        };
        Fy[i] = (cpp) {
            x, y
        };
    }

    sort(Fx + 1, Fx + n + 1, cmpx);
    sort(Fy + 1, Fy + n + 1, cmpy);
    scanf("%d", &q);

    while (q--) {
        int lx, ly, rx, ry, sum = 0;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        sum += upper_bound(Fx + 1, Fx + n + 1, (cpp) {
            lx, ry - 1
        }, cmpx) - lower_bound(Fx + 1, Fx + n + 1, (cpp) {
            lx, ly
        }, cmpx);
        sum += upper_bound(Fx + 1, Fx + n + 1, (cpp) {
            rx, ry
        }, cmpx) - lower_bound(Fx + 1, Fx + n + 1, (cpp) {
            rx, ly + 1
        }, cmpx);
        sum += upper_bound(Fy + 1, Fy + n + 1, (cpp) {
            rx - 1, ry
        }, cmpy) - lower_bound(Fy + 1, Fy + n + 1, (cpp) {
            lx, ry
        }, cmpy);
        sum += upper_bound(Fy + 1, Fy + n + 1, (cpp) {
            rx, ly
        }, cmpy) - lower_bound(Fy + 1, Fy + n + 1, (cpp) {
            lx + 1, ly
        }, cmpy);
        printf("%d\n", sum);
    }

    return 0;
}

