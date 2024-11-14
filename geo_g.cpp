#include<bits/stdc++.h>
using namespace std;
double xa,ya,xb,yb,xc,yc,a,b,c;
int main() {
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    double x_0=xa-xb,y_0=ya-yb;
    double x_1=xc-xb,y_1=yc-yb;
    double x=x_0*x_1+y_0*y_1;
    double y=sqrt(x_0*x_0+y_0*y_0)*sqrt(x_1*x_1+y_1*y_1);
    double angle=acos(x/y);
    cout.precision(9);
    if (angle>=M_PI) angle-=M_PI;
    if (angle<=M_PI/2) {
        a=yc-yb;
        b=xb-xc;
        c=xc*yb-xb*yc;
        double t1=abs(a*xa+b*ya+c);
        double t2=sqrt(a*a+b*b);
        cout<<fixed<<t1/t2;
    } else {
        cout<<fixed<<sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
    }
}

