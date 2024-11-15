#include <bits/stdc++.h>
#define ll long long int

using namespace std;

char k;
vector <char> a,b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>k){
        (k>='A' && k<='Z') ? a.push_back(k) : b.push_back(k);
    }
    sort(a.begin(),a.end(),greater<char>());
    sort(b.begin(),b.end(),greater<char>());
    for (auto x : a) cout<<x;
    for (auto x : b) cout<<x;
}

