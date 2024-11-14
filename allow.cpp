#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct coin {int v,b;}coin;

coin cn[30];
int n,c,sum=0,k=0;

bool cmp(coin a,coin b) {return a.v<b.v;}

inline int read(){
    int num=0,k=1; char c=getchar();
    while(c>'9' || c<'0') k=(c=='-')?-1:k,c=getchar();
    while(c>='0' && c<='9') num=(num<<3)+(num<<1)+c-'0',c=getchar();
    return num*k;
}

int main() {
    n=read(); c=read();
    for(int i=1;i<=n;i++){
        int v=read(),b=read();
        if(v>=c) {sum+=b; continue;}
        cn[++k].v=v; cn[k].b=b;
    }
    sort(cn+1,cn+k+1,cmp);
    while(true){
        int x=c,v[30]={0};
        for(int i=k;i>=1;i--){
            if(cn[i].b<=0 || cn[i].v>x) continue;
            if(cn[i].b>=x/cn[i].v) v[i]+=x/cn[i].v,x=x%cn[i].v;
            else v[i]+=cn[i].b,x-=cn[i].b*cn[i].v;
        }
        for(int i=1;i<=k;i++){
            if(x<=0) break;
            if(cn[i].b-v[i]<=0 || x>cn[i].v) continue;
            x-=cn[i].v; v[i]++;
        }
        if(x>0) break;
        int ans=1000000000;
        for(int i=1;i<=k;i++) if(v[i]) ans=min(ans,cn[i].b/v[i]);
        for(int i=1;i<=k;i++) cn[i].b-=ans*v[i];
        sum+=ans;
    }
    printf("%d",sum);
    return 0;
}

