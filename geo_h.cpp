#include<bits/stdc++.h>
using namespace std;
double xa,xb,xc,ya,yb,yc,a,b,c;
double angle(double x_0,double y_0,double x_1,double y_1) {
    double x=x_0*x_1+y_0*y_1;
    double y=sqrt(x_0*x_0+y_0*y_0)*sqrt(x_1*x_1+y_1*y_1);
    return acos(x/y);
}
int main() {
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    cout.precision(9);
    if (angle(xa-xb,ya-yb,xc-xb,yc-yb)<=M_PI/2&&angle(xa-xc,ya-yc,xb-xc,yb-yc)<=M_PI/2) {
        a=yc-yb;
        b=xb-xc;
        c=xc*yb-xb*yc;
        double t1=abs(a*xa+b*ya+c);
        double t2=sqrt(a*a+b*b);
        cout<<fixed<<t1/t2;
    } else if (angle(xa-xb,ya-yb,xc-xb,yc-yb)>M_PI/2) {
        cout<<fixed<<sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
    } else {
        cout<<fixed<<sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
    }
}

