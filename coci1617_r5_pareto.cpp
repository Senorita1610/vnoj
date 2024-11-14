#include <bits/stdc++.h>
 
template<class A, class B>
bool maximize(A &a, const B& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class A, class B>
bool minimize(A &a, const B& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;
 
constexpr int MAX_N = 300005;
 
int N;
long long sum, total;
vector<int> balances;
double maximum, A, B, a, b;
 
signed main() {
    #ifdef LOCAL
    freopen("input.INP", "r", stdin);
    #endif // LOCAL
 
    cin.tie(0) -> sync_with_stdio(0);
    cout.tie(0);
    cout.precision(9);
    cout.setf(ios::fixed, ios::floatfield);
 
    cin >> N;
 
    balances.resize(N);
 
    for (int &balance : balances) {
        cin >> balance;
        sum += balance;
    }
 
    sort(balances.rbegin(), balances.rend());
 
    for (int i = 0; i < N; ++i) {
        total += balances[i];
        a = (i + 1.0) / N;
        b = 1.0 * total / sum;
        if (maximize(maximum, b - a)) {
            A = a;
            B = b;
        }
    }
 
    cout << A * 100 << '\n' << B * 100 << '\n';
 
    return 0;
}

