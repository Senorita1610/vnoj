#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5+5;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define fr first
#define sc second
 
int n, q;
string ans;
int main() {
 
    cin >> n >> q;
 
    for(int i = 1; i <= n; i++) ans += '.';
 
    stack<int> fila;
 
    for(int i = 1; i <= n; i++) {
        if(fila.empty()) {
            fila.push(i);
            continue;
        }
        
        int x = fila.top(), aux;
        assert(1 <= x and x <= n);
        cout << "? " << x << " " << i << endl;
        cout.flush();
        cin >> aux;
        
        if(aux) {
            fila.pop();
            ans[x-1] = '(';
            ans[i-1] = ')';
            continue;
        }
 
        fila.push(i);
    }
 
    int s = sz(fila);
    for(int i = 1; i <= s; i++) {
        assert(fila.top() >= 1 and fila.top() <= n);
        if(i <= s/2) ans[fila.top()-1] = '(';
        else ans[fila.top()-1] = ')';
        fila.pop();
    }
 
    cout << "! " << ans << endl;
    cout.flush();
}

