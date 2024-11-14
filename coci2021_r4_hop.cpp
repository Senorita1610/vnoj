#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define MNTO(x,y) x=min(x,y)
#define MXTO(x,y) x=max(x,y)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
const int maxn=1e5+5;
ll arr[maxn];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    cin>>n;
    REP(i,n) cin>>arr[i];
    REP(i,n){
        REP(j,i){
            int a=__lg(arr[i]),b=__lg(arr[j]);
            if(a/4==b/4) cout<<"2 ";
            else if(a/16==b/16) cout<<"1 ";
            else cout<<"3 ";
        }
        cout<<'\n';
    }
}

