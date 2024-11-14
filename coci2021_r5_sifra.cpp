#include<bits/stdc++.h>
using namespace std;
set<string> st;
int main() {
    string str, str2;
    cin >> str;
    for(auto i: str) {
        if(i<'a')
            str2+=i;
        else
            st.insert(str2),str2="";
    }
    st.insert(str2);
    st.erase("");
    cout << st.size();
}

