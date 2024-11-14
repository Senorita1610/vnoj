#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll x,y,a=0,b=1,c,i=0,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x>>y;
    if (x==y){
        cout<<0<<" "<<0;
        return 0;
    }
    c=x;
    while (1){
        i++;
        if (a==0) a++;
        else a*=2;
        b*=-1;
        ans+=abs(x+a*b-c);
        c=x+a*b;
        if ((x<=y && y<=c) || (x>=y && y>=c)){
            cout<<i<<" "<<ans-abs(y-c);
            return 0;
        }
    }
}

