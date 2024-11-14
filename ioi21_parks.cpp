#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define sz(A) int(A.size())
#define pii pair<int,int>
const int N = 2e5+5;
vi U,V,A,B;
int p[N],fa[N],lst[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void add(int u,int v,int a,int b){
    fa[find(u)]=find(v);
    U.push_back(u-1),V.push_back(v-1);
    A.push_back(a),B.push_back(b);
    if(a>lst[b])lst[b] = a;
}
struct node{int x,y;}v[N];
bool cmp(int x,int y){return v[x].x==v[y].x?v[x].y<v[y].y:v[x].x<v[y].x;}
int construct_roads(vi x,vi y){
    int n = sz(x);
    for(int i=1;i<=n;i++)fa[i]=p[i]=i,v[i]={x[i-1],y[i-1]};
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++){
        int id = p[i];
        auto [x,y] = v[id];
        bool odd = (x^y)&2;
        if(i>1 && v[p[i-1]].x==x && v[p[i-1]].y==y-2){//vertical
            int k = p[i-1];
            if(find(k)!=find(id)){
                if(odd){
                    if(lst[y-1]==x-1)add(lst[y],id,x-1,y+1);
                    else add(k,id,x-1,y-1);
                }else add(k,id,x+1,y-1);
            }
        }
        if(lst[y] && v[lst[y]].x == x-2){//horizontal
            int k = lst[y];
            if(find(k)!=find(id)){
                if(odd)add(k,id,x-1,y+1);
                else{
                    if(lst[y-1]==x-1){}
                    else add(k,id,x-1,y-1);
                }
            }
        }
        lst[y] = id;
    }
    int c=0;
    for(int i=1;i<=n;i++)c+=(fa[i]==i);
    if(c>1)return 0;
    build(U,V,A,B);
    return 1;
}

