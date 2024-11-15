#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
string s;
ll cnt = 0;
int main() {
    nothing
    cin >> s;
    for (int i = 0; i < s.size(); ++i) 
    	if (s[i] >= '0' && s[i] <= '9') cnt++;
    cout << cnt << endl;
    return 0;
}

