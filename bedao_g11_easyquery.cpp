#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
struct query{
    int type;
    int l,r;
    int x;
};
int n,q;
ll a[N+5];
query qu[N+5];
struct Node{
    ll val,lazy;
};
Node st[N*4+5];
void build (int id,int l,int r){
    if (l==r) {
        st[id].val=a[l];
        return;
    }
    int mid=(l+r)/2;
    build (id*2,l,mid);
    build (id*2+1,mid+1,r);
    st[id].val=st[id*2].val+st[id*2+1].val;
}
void down(int id,int l,int r) {
    int mid=(l+r)/2;
    ll t=st[id].lazy;
    st[id].lazy=0;
    st[id*2].lazy+=t;
    st[id*2].val+=t*(mid-l+1);
    st[id*2+1].lazy+=t;
    st[id*2+1].val+=t*(r-mid);
}
void update(int id,int l,int r,int u,int v,ll val) {
    if (l>v||r<u) return;
    if (u<=l&&r<=v) {
        st[id].val+=val*(r-l+1);
        st[id].lazy+=val;
        return;
    }
    int mid=(l+r)/2;
    down(id,l,r);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id].val=st[id*2].val+st[id*2+1].val;
    //cout<<id<<' '<<l<<' '<<r<<' '<<st[id].val<<endl;
}
ll get(int id,int l,int r,int u,int v) {
    if (l>v||r<u) return 0;
    if (u<=l&&r<=v) return st[id].val;
    int mid=(l+r)/2;
    down(id,l,r);
    ll get1=get(id*2,l,mid,u,v);
    ll get2=get(id*2+1,mid+1,r,u,v);
    return get1+get2;
}
int main() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for (int i=1;i<=q;i++) {
        cin>>qu[i].type;
        if(qu[i].type==1) {
            cin>>qu[i].l>>qu[i].r>>qu[i].x;
            update(1,1,n,qu[i].l,qu[i].r,qu[i].x);
        } else if (qu[i].type==2) {
            int temp;
            cin>>temp;
            qu[i].l=qu[temp].l;
            qu[i].r=qu[temp].r;
            qu[i].x=-qu[temp].x;
            update(1,1,n,qu[i].l,qu[i].r,qu[i].x);
        } else {
            cin>>qu[i].l>>qu[i].r;
            cout<<get(1,1,n,qu[i].l,qu[i].r)<<endl;
        }
    }
}

