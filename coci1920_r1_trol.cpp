#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q; cin >> Q;
    while(Q--){
        ll L, R; cin >> L >> R;
        ll ans = (R/9)*45 - ((L + 8)/9)*45;
        for(int i = 1; i <= R % 9; i++) ans += i;
 
        ll tmp = L%9;
        if(tmp == 0) tmp = 9;
        for(int i = tmp; i <= 9; i++) ans += i;
 
        cout << ans << '\n';
    }
 
    return 0;
}

