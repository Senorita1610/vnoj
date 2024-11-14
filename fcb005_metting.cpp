#include<bits/stdc++.h>
using namespace std;
int n;
char c;
string s;
int main() {
    cin>>n>>c;
    while (n--) {
        bool flag=true;
        cin>>s;
        for (auto i:s) if (i==c) {
            flag=false;
            break;
        }
        if (flag) cout<<s<<endl;
    }
}

