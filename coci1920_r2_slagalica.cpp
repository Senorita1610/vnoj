#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt")
#include<bits/stdc++.h>
#define int long long
#define quick ios::sync_with_stdio(0);cin.tie(0);
#define rep(x,a,b) for(int x=a;x<=b;x++)
#define repd(x,a,b) for(int x=a;x>=b;x--)
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define lowbit(x) (x&-x)
#define sz(x) (int)(x.size())
using namespace std;
typedef pair<int,int> pii;
void debug(){
    cerr<<"\n";
}
template<class T,class ...U>
void debug(T a,U ...b){
    cout<<a<<" ",debug(b...);
}
const int N=2e5+7;
const int INF=1e18;
int in[6];
int out[6];
vector<pii> v[6];
vector<int> res;
vector<int> v2[4];
void add_edge(int a,int b,int w){
    v[a].eb(mp(w,b));
    //debug(a,"=>",b);
    in[b]++;
    out[a]++;
}
pii e[8]={mp(1,2),mp(1,1),mp(2,2),mp(2,1),mp(0,2),mp(0,1),mp(1,4),mp(2,4)};
int t[N];
void dfs(int x){
    //debug(x,":",t[x]);
    //system("pause");
    for(int &i=t[x];i<sz(v[x]);){
        pii nw=v[x][i++];
        dfs(nw.S);
        res.eb(nw.F);
    }
}
signed main(){
    quick
    int n;
    int st=0;
    int ed=4;
    cin>>n;
    int stw=0;
    int ew=0;
    rep(i,1,n){
        int xi,ai;
        cin>>xi>>ai;
        add_edge(e[xi-1].F,e[xi-1].S,ai);
    }
    if(out[st]!=1||in[ed]!=1){
        cout<<"-1\n";
    }
    else{
        add_edge(ed,st,INF);
        rep(i,0,4){
            if(in[i]!=out[i]){
                cout<<"-1\n";
                return 0;
            }
            sort(all(v[i]));
        }
        //rep(i,0,4) debug(in[i],out[i]);
        dfs(st);
        reverse(all(res));
        rep(i,0,n-1) cout<<res[i]<<" \n"[i==n-1];
    }
 
 
 
 
 
}

