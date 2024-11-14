#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long a[N+5];
long long l[N+5],r[N+5],d[N+5];
long long inf=1e16;
long long res=inf;
struct Node{
    long long lazy;
    long long val;
} nodes[4*N+5];
void down(int id) {
    long long t=nodes[id].lazy;
    nodes[id*2].lazy+=t;
    nodes[id*2].val+=t;
    nodes[id*2+1].lazy+=t;
    nodes[id*2+1].val+=t;
    nodes[id].lazy=0;
}
void build (int id,int l,int r) {
    if (l==r) {
        nodes[id].val=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    nodes[id].val=max(nodes[id*2].val,nodes[id*2+1].val);
}
void update(int id,int l,int r,int u,int v,long long val) {
    if (v<l||u>r) return;
    if (u<=l&&r<=v) {
        nodes[id].lazy+=val;
        nodes[id].val+=val;
        return;
    }
    int mid=(l+r)/2;
    down(id);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    nodes[id].val=max(nodes[id*2].val,nodes[id*2+1].val);
}
long long get(int id,int l,int r,int u,int v) {
    if (v<l||u>r) return -inf;
    if (u<=l&&r<=v) return nodes[id].val;
    int mid=(l+r)/2;
    down(id);
    long long get1=get(id*2,l,mid,u,v);
    long long get2=get(id*2+1,mid+1,r,u,v);
    return max(get1,get2);
}
int main() {
    cin>>n>>m;
    build(1,1,n);
    for (int i=1;i<=m;i++) {
        cin>>l[i]>>r[i]>>d[i];
        update(1,1,n,l[i],r[i],d[i]);
    }
    res=get(1,1,n,1,n);
    for (int i=1;i<=m;i++) {
        update(1,1,n,l[i],r[i],-d[i]);
        res=min(res,get(1,1,n,1,n));
        update(1,1,n,l[i],r[i],d[i]);
    }
    cout<<res;
}

