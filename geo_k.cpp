#include<bits/stdc++.h>
using namespace std;
double xa,xb,ya,yb;
int main() {
    cin>>xa>>ya>>xb>>yb;
    cout.precision(9);
    cout<<fixed<<sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

