#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll S=100,L=10;
ll t,r1,o1,r2,o2;
void Solve(){
    cin>>r1>>o1>>r2>>o2;
    if (S*o1<=(r1+o1)*L && S*o2<=(r2+o2)*L){
        if (r1+o1>r2+o2) cout<<"Megumin"<<endl;
        else if (r1+o1<r2+o2) cout<<"Yunyun"<<endl;
        else cout<<"Draw"<<endl;
    }
    else if (S*o1<=(r1+o1)*L && S*o2>(r2+o2)*L){
        if (S*r2<(r1+o1)*(S-L)) cout<<"Megumin"<<endl;
        else if (S*r2>(r1+o1)*(S-L)) cout<<"Yunyun"<<endl;
        else cout<<"Draw"<<endl;
    }
    else if (S*o1>(r1+o1)*L && S*o2<=(r2+o2)*L){
        if ((r2+o2)*(S-L)<S*r1) cout<<"Megumin"<<endl;
        else if ((r2+o2)*(S-L)>S*r1) cout<<"Yunyun"<<endl;
        else cout<<"Draw"<<endl;
    }
    else if (S*o1>(r1+o1)*L && S*o2>(r2+o2)*L){
        if (r1>r2) cout<<"Megumin"<<endl;
        else if (r1<r2) cout<<"Yunyun"<<endl;
        else cout<<"Draw"<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

