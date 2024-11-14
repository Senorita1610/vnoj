#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,q,a,b,c,d,x,y,z,t;
ll Check(ll x){
    return (x>=1 && x<=n);
}
void Solve(){
    cin>>a>>b>>c>>d;
    if ((a+b)%2!=(c+d)%2) cout<<-1<<endl;
    else if (a==c && b==d) cout<<0<<endl;
    else if (a+b==c+d || a-b==c-d) cout<<1<<endl<<c<<" "<<d<<endl;
    else{
        x=a+b,y=c-d;
        z=c+d,t=a-b;
        if (Check((x+y)/2)==1 && Check((x-y)/2)==1) cout<<2<<endl<<(x+y)/2<<" "<<(x-y)/2<<endl;
        else if (Check((z+t)/2)==1 && Check((z-t)/2)==1) cout<<2<<endl<<(z+t)/2<<" "<<(z-t)/2<<endl;
        cout<<c<<" "<<d<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    while (q--) Solve();
}

