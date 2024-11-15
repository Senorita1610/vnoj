#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
string s;
ll n, cnt = 0;
int main() {
    nothing
    cin >> s;
    n = s.size();
    s = '#' + s;
    int pos = 1;
    while (pos <= n - 5 + 1) {
    	if (s[pos] == 'v')
    		if (s[pos + 1] == 'i')
    			if (s[pos + 2] == 'r')
    				if (s[pos + 3] == 'u')
    					if (s[pos + 4] == 's') {
    						pos = pos + 5;
    						cnt++;
    						continue;
    					}
    	pos++;
    }
    cout << cnt << endl;
    return 0;
}

