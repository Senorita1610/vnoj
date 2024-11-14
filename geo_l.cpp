#include<bits/stdc++.h>
using namespace std;
long long xa,xb,ya,yb,a,b,c;
int main() {
    cin>>xa>>ya>>xb>>yb;
    a=yb-ya;
    b=xa-xb;
    c=xb*ya-xa*yb;
    cout<<a<<' '<<b<<' '<<c;
}

