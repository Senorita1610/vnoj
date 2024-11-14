#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50005;
map<int,bitset<N> > mp;
int n;
int a[50005][6];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
            mp[a[i][j]].set(i);
        }
    }
    bitset<N> p;
    long long ans=0;
    for(int i=1;i<=n;i++){
        p.reset();
        for(int j=1;j<=5;j++) p|=mp[a[i][j]];
        ans+=n-p.count();
    }
    printf("%lld",ans/2);
    return 0;
}

