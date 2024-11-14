#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans;
int cr[1005][1005];
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char op;
            cin>>op;
            cr[i][j]=op=='C'?1:op=='G'?2:0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cr[i][j]==2){
                if(cr[i-1][j]==1&&cr[i+1][j]==1||cr[i][j-1]==1&&cr[i][j+1]==1) cr[i][j]=0,ans++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cr[i][j]==1&&cr[i+1][j-1]==1){
                if(cr[i][j-1]==2) cr[i][j-1]=0,ans++;
                else if(cr[i+1][j]==2) cr[i+1][j]=0,ans++;
            }
            if(cr[i][j]==1&&cr[i+1][j+1]==1){
                if(cr[i][j+1]==2) cr[i][j+1]=0,ans++;
                else if(cr[i+1][j]==2) cr[i+1][j]=0,ans++;
            } 
        }
    }
    printf("%lld",ans);
    return 0;
}

