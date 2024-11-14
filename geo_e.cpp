#include<bits/stdc++.h>
using namespace std;
double x,y,a,b,c;
int main() {
    cin>>x>>y>>a>>b>>c;
    double t1=abs(a*x+b*y+c);
    double t2=sqrt(a*a+b*b);
    cout.precision(9);
    cout<<fixed<<t1/t2;
}

