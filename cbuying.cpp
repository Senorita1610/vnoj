#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define mem(i,j) memset(i,j,sizeof(i))
#define int long long 
using namespace std;
inline int read(){
    int res=0,f=1;char ch=' ';
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
    return res*f;
}
void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=1e7+5;
int n,m,ans;
struct node{
    int p,c;
}q[N];
bool cmp(node x,node y){return x.p<y.p;}
#undef int 
int main(){
    n=read(),m=read();
    for(register int i=1;i<=n;i++)q[i].p=read(),q[i].c=read();
    sort(q+1,q+n+1,cmp);
    for(register int i=1;i<=n;i++){
        long long k=m/q[i].p;
        if(k>q[i].c)ans+=q[i].c,m-=q[i].p*q[i].c;
        else{ans+=k;break;}
    }
    printf("%lld",ans);
    return 0;
}

