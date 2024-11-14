#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,k,tot,dp[N][52],cnt;
vector<int>edge[N];
struct node{int l,r,num;}s[N];
void print(int x){cout<<(x-1)/m+1<<' '<<(x-1)%m+1<<'\n';}
void dfs(int x){
    if(x%m==1){s[x]={++tot,tot,x};}
    for(int to:edge[x]) 
        dfs(to),
        s[x].l=min(s[x].l,s[to].l),
        s[x].r=max(s[x].r,s[to].r);
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n*m;i++){
        char c;cin>>c;
        s[i]={INT_MAX,-1,i};
        if(i%m==0) continue;
        if(c=='U') edge[i-m].push_back(i);
        if(c=='D') edge[i+m].push_back(i);
        if(c=='R') edge[i+1].push_back(i);
        if(c=='L') edge[i-1].push_back(i);
    }
    for(int i=1;i<=n;i++) for(int to:edge[i*m]) dfs(to);
    dp[0][0]=1;
    sort(s+1,s+n*m+1,[](node x,node y){return x.r<y.r;});
    for(int i=1;i<=n*m&&cnt<k;i++) if(s[i].r==-1&&s[i].num%m) dp[0][++cnt]=i;
    for(int i=1;i<=n*m;i++){
        if(s[i].r==-1) continue;
        for(int j=0;j<k;j++)
            if(dp[s[i].l-1][j]) dp[s[i].r][j+1]=i;
    }
    
    if(!dp[tot][k]) cout<<-1<<'\n';
    else{
        int nw=tot;
        for(int i=k;i>=1;i--){
            print(s[dp[nw][i]].num);
            if(s[dp[nw][i]].r==-1) nw=0;
            else nw=s[dp[nw][i]].l-1;
        }
    }
    return 0;
}

