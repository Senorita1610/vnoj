#include<bits/stdc++.h>
using namespace std;
double a1,b1,c1,a2,b2,c2,d,dx,dy;
int main() {
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    c1=-c1;
    c2=-c2;
    d=a1*b2-a2*b1;
    dx=c1*b2-c2*b1;
    dy=a1*c2-a2*c1;
    cout.precision(9);
    cout<<fixed<<dx/d<<' '<<dy/d;
}

