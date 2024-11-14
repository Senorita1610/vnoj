#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int res;
pair<int,int>p[N+5];
int calc(int i,int j) {
    return abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            res=max(res,calc(i,j));
    cout<<res;
}

