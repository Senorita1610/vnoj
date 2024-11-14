#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
int C,Kof[200100];
VI ans;
struct segtree{
    struct DATA{
        long long prfmn,prfmx,sum;
        DATA(long long k){
            prfmn=min(0ll,k),
            prfmx=max(0ll,k),sum=k;
        }
        DATA(){
            prfmn=prfmx=sum=0;
        }
        DATA(DATA a,DATA b){ sum=a.sum+b.sum;
            prfmn=min(a.prfmn,b.prfmn+a.sum);
            prfmx=max(a.prfmx,b.prfmx+a.sum);
        }
    } T[1<<19];
    void Add(int i,int l,int r,int p,int v){
        if(l==r) return void(T[i]=DATA(T[i].sum+v));
        if(l+r>>1>=p) Add(i*2,l,l+r>>1,p,v);
        else Add(i*2+1,l+r+2>>1,r,p,v);
        T[i]=DATA(T[i*2],T[i*2+1]);
    }
    int getans(DATA k,int b){
        return (b?k.prfmx>C:k.prfmn>=-C)?C+k.sum-k.prfmx:k.sum-k.prfmn;
    }
    int Qry(int i,int l,int r,DATA prv){
        if(l==r) return getans(DATA(T[i],prv),T[i].sum>=0);
        DATA c=DATA(T[i*2+1],prv);
        if(c.prfmx-c.prfmn<=C)
            return Qry(i*2,l,l+r>>1,c);
        return Qry(i*2+1,l+r+2>>1,r,prv);
    }
} seg;
vector<pair<int,int>> stuf[200100];
VI distribute_candies(VI c,VI l,VI r,VI v) {
    int n=c.size(),q=l.size();
    for(int i=0;i<q;i++)
        stuf[l[i]].push_back({i+1,v[i]}),
        stuf[r[i]+1].push_back({i+1,-v[i]});
    for(int i=0;i<n;i++){
        for(auto[a,b]:stuf[i])
            seg.Add(1,0,q,a,b);
        C=c[i];
        ans.push_back(seg.Qry(1,0,q,seg.T[0]));
    }
    return ans;
}

