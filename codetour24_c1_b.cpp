#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
ll n, k, num;
int main() {
    nothing
    cin >> n >> k;
    num = n / k + ((n % k) > 0);
    cout << (num + 1) * num / 2 << endl;
    return 0;
}

