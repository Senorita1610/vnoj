#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
struct Segtree{
    int st[N*4+5];
    void update(int id,int l,int r,int pos,int val) {
        if (l>pos||r<pos) return;
        if (l==r) {
            st[id]+=val;
            return;
        }
        int mid=(l+r)/2;
        update(id*2,l,mid,pos,val);
        update(id*2+1,mid+1,r,pos,val);
        st[id]=st[id*2]+st[id*2+1];
    }
    int get(int id,int l,int r,int u,int v) {
        if (r<u||l>v) return 0;
        if (u<=l&&r<=v) return st[id];
        int mid=(l+r)/2;
        return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
    }
} tree[26];
int n,l,r,q,type,t;
char c;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>s;
    s=' '+s;
    for (int i=1;i<=n;i++) tree[s[i]-'a'].update(1,1,n,i,1);
    cin>>q;
    while (q--) {
        cin>>type;
        if (type==1) {
            cin>>t>>c;
            tree[s[t]-'a'].update(1,1,n,t,-1);
            s[t]=c;
            tree[s[t]-'a'].update(1,1,n,t,1);
        } else {
            int cnt=0;
            cin>>l>>r;
            for (int i=0;i<26;i++) {
                if (tree[i].get(1,1,n,l,r)>0) cnt++;
            }
            cout<<cnt<<'\n';
        }
    }
}

