#include<bits/stdc++.h>
using namespace std;
double x,y,tn;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>x>>y;
    cout.precision(9);
    if (x>0&&y>0) {
        cout<<fixed<<atan(y/x);
    } else if (x<0&&y>0) {
        x=abs(x);
        cout<<fixed<<M_PI-atan(y/x);
    } else if (x<0&&y<0) {
        x=abs(x);
        y=abs(y);
        cout<<fixed<<M_PI+atan(y/x);
    } else if (x>0&&y<0) {
        y=abs(y);
        cout<<fixed<<2*M_PI-atan(y/x);
    } else if (x==0&&y==0) cout<<fixed<<0;
    else if (x==0&&y>0) cout<<fixed<<M_PI/2;
    else if (x==0&&y<0) cout<<fixed<<M_PI+M_PI/2;
    else if (x>0&&y==0) cout<<0;
    else if (x<0&&y==0) cout<<M_PI;
}

