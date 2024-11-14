#include<bits/stdc++.h>
#define inf 1000000000.0
using namespace std;
int const N=2333;
int n,w,x[N],y[N],vis[N],ans;
double m,f[N][N],d[N];
double dis(int i,int j){
    return sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j]));
}
int main(){
    scanf("%d%d%lf",&n,&w,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)f[i][j]=inf;
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            double k=dis(i,j);
            if(k<m)f[i][j]=k;
        }
    for(int i=1;i<=w;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        f[a][b]=f[b][a]=0;
    }
    for(int i=2;i<=n;i++)d[i]=inf;
    for(int i=1;i<=n;i++){
        int k=0;
        for(int j=1;j<=n;j++)if(!vis[j]&&(!k||d[k]>d[j]))k=j;
        vis[k]=1;
        for(int j=1;j<=n;j++)if(!vis[j]&&d[j]>d[k]+f[k][j])d[j]=d[k]+f[k][j];
    }
    if(d[n]==inf)puts("-1");else printf("%d",int(d[n]*1000));
}

