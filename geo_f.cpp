#include<bits/stdc++.h>
using namespace std;
double xa,ya,xb,yb,xc,yc,a,b,c;
int main() {
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    a=yc-yb;
    b=xb-xc;
    c=xc*yb-xb*yc;
    double t1=abs(a*xa+b*ya+c);
    double t2=sqrt(a*a+b*b);
    cout.precision(9);
    cout<<fixed<<t1/t2;
}

