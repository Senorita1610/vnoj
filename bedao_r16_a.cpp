#include<bits/stdc++.h>
using namespace std;
string s;
string t;
int main() {
    getline(cin,s);
    for (auto i:s) {
        if (i==' ') break;
        t+=i;
    }
    if (t=="I") cout<<"am";
    else if (t=="We"||t=="They"||t=="You") cout<<"are";
    else cout<<"is";
}

