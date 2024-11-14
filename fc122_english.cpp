#include <bits/stdc++.h>
#define ll long long int

using namespace std;

double a,b,c,d,s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>d;
    s=(a+b+c+d)/4;
    s=round(s*2);
    s/=2;
    if (s<4) cout<<fixed<<setprecision(1)<<s;
    else if (s>=4){
        cout<<fixed<<setprecision(1)<<s;
        if (s<=5) cout<<" B1";
        else if (s<=6.5) cout<<" B2";
        else if (s<=8) cout<<" C1";
        else cout<<" C2";
    }
}

