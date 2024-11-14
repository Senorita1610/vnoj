#include<bits/stdc++.h>

using namespace std;

using I=int;
using Lli=long long int;
using B=bool;

const I N=2e5;
const I M=2e5;
const I LOGN=18;
const I MIN=-1e9;

tuple<I,I,I>edgs[M];
I inds[M];
I pars[N];
vector<pair<I,I>>adjs[N];
I ancs[N][LOGN];
I wgts[N][LOGN];
I tbegs[N],tends[N];
I t=0;

I fnd(I i){
  if(pars[i]<0)return i;
  return pars[i]=fnd(pars[i]);
}

B uni(I a,I b){
  if((a=fnd(a))==(b=fnd(b)))return 0;
  if(pars[a]>pars[b])swap(a,b);
  pars[a]+=pars[b],pars[b]=a;
  return 1;
}

void dfs(I a,I p,I d){
  tbegs[a]=t++;
  wgts[a][0]=d;
  ancs[a][0]=p;
  for(I i=1;i<LOGN;i++){
    I b=ancs[a][i-1];
    wgts[a][i]=max(wgts[a][i-1],wgts[b][i-1]);
    ancs[a][i]=ancs[b][i-1];
  }
  for(auto[b,w]:adjs[a])if(b!=p)dfs(b,a,w);
  tends[a]=t++;
}

B anc(I a,I b){
  return tbegs[a]<=tbegs[b]&&tends[a]>=tends[b];
}

I qry(I a,I b){
  I res=MIN;
  for(I i=LOGN-1;i>=0;i--){
    if(anc(ancs[a][i],b))continue;
    res=max(res,wgts[a][i]);
    a=ancs[a][i];
  }
  if(!anc(a,b)){
    res=max(res,wgts[a][0]);
    a=ancs[a][0];
  }
  for(I i=LOGN-1;i>=0;i--){
    if(anc(ancs[b][i],a))continue;
    res=max(res,wgts[b][i]);
    b=ancs[b][i];
  }
  if(!anc(b,a)){
    res=max(res,wgts[b][0]);
    b=ancs[b][0];
  }
  return res;
}

B cmp(I a,I b){
  return edgs[a]<edgs[b];
}

I main(){
  cin.tie(0)->sync_with_stdio(0);
  I n,m;cin>>n>>m;
  fill_n(pars,n,-1);
  for(I i=0;i<m;i++){
    I u,v,w;cin>>u>>v>>w;
    edgs[i]={w,u-1,v-1};
  }
  iota(inds,inds+m,0);
  sort(inds,inds+m,cmp);
  Lli res=0;
  for(I i=0;i<m;i++){
    auto[w,u,v]=edgs[inds[i]];
    if(!uni(u,v))continue;
    res+=w;
    adjs[u].push_back({v,w});
    adjs[v].push_back({u,w});
  }
  dfs(0,0,MIN);
  for(I i=0;i<m;i++){
    auto[w,u,v]=edgs[i];
    printf("%lli\n",res+w-qry(u,v));
  }
}

