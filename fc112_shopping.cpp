#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;
int A,B,M,a[N],b[N],answer=INF,x,y,z;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B>>M;
    for(int i=1;i<=A;i++) cin>>a[i];
    for(int i=1;i<=B;i++) cin>>b[i];
    answer=min(answer,*min_element(a+1,a+A+1)+*min_element(b+1,b+B+1));
    for(int i=1;i<=M;i++){
        cin>>x>>y>>z;
        answer=min(answer,a[x]+b[y]-z);
    }
    cout<<answer;
}

