#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
multiset<int>s;
int n,m,c;
int a[N+5];
bool flag=false;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>c;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) s.insert(a[i]);
    if ((*s.rbegin())-(*s.begin())<=c) {
        cout<<1<<'\n';
        flag=true;
    }
    for (int i=2;i<=n-m+1;i++) {
        s.erase(s.find(a[i-1]));
        s.insert(a[i+m-1]);
        if ((*s.rbegin())-(*s.begin())<=c) {
            cout<<i<<'\n';
            flag=true;
        }
    }
    if (!flag) cout<<"NONE";
}

