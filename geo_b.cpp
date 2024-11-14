#include<bits/stdc++.h>
using namespace std;
double x_1,y_1,x_0,y_0;
int main() {
    cin>>x_0>>y_0>>x_1>>y_1;
    double x=x_0*x_1+y_0*y_1;
    double y=sqrt(x_0*x_0+y_0*y_0)*sqrt(x_1*x_1+y_1*y_1);
    cout.precision(9);
    cout<<fixed<<acos(x/y);
}

