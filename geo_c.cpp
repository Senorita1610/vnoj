#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct Point{
    double x,y;
}p[N+5];
int n;
double res;
double calc(int i,int j,int k) {
    double a=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
    double b=sqrt((p[i].x-p[k].x)*(p[i].x-p[k].x)+(p[i].y-p[k].y)*(p[i].y-p[k].y));
    double c=sqrt((p[k].x-p[j].x)*(p[k].x-p[j].x)+(p[k].y-p[j].y)*(p[k].y-p[j].y));
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
    for (int i=2;i<n;i++) res+=calc(1,i,i+1);
    cout.precision(9);
    cout<<fixed<<res;
}

