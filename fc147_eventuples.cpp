#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,q,a[N],x,y,c,l;
struct Node{
    ll Chan,Le;
};
Node ST[N];
void Build(){
    ST[0].Chan=0;
    ST[0].Le=0;
    for (ll i=1;i<=n;i++){
        ST[i].Chan=ST[i-1].Chan+(a[i]%2==0);
        ST[i].Le=ST[i-1].Le+(a[i]%2==1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    Build();
    while (q--){
        cin>>x>>y;
        c=ST[y].Chan-ST[x-1].Chan;
        l=ST[y].Le-ST[x-1].Le;
        cout<<c*(c-1)*(c-2)/6+l*(l-1)*c/2<<endl;
    }
}

