#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    stack<int> st;
    cin >> s;
    s = '(' + s + ')';
    int ans = 0;
    for (int i=0; i<s.length(); i++){
        if (s[i] == '(') st.push(10001);
        else if (s[i] == ')'){
            int tmp1 = 0;
            while (st.top() != 10001){
                tmp1 += st.top();
                st.pop();
            }
            st.pop();
            st.push(tmp1);
            if (i == s.length() - 1){
                ans += tmp1;
            }
        }
        else if (s[i] == 'C') st.push(12);
        else if (s[i] == 'O') st.push(16);
        else if (s[i] == 'H') st.push(1);
        else{
            int tmp = st.top() * (int)(s[i] - '0');
            st.pop();
            st.push(tmp);
        }
    }
    cout << ans;
}

