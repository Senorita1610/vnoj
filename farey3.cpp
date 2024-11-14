#include <bits/stdc++.h>
#define fi first
#define sec second
#define ll long long
using namespace std;
const int MAXN=5e5+100;
ll n,k;
int z[MAXN];
double BS(double le,double ri){
    double r=(le+ri)/2;
    double ans=0;
    for(int i=1;i<=n;i++){
        int k2=i*r;
        double v=i;
        double k=v*r;
        if(k2==k){
            k2--;
        }
        ans+=(k2)*z[i];
    }
    if(ans==k){
        return r;
    }
    if(ans>k){
        return BS(le,r);
    }
    else{
        return BS(r,ri);
    }
}
main(){
    cin>>n>>k;
    z[n]=1;
    for(int i=n-1;i>=1;i--){
        z[i]=1;
        for(int j=2;j*i<=n;j++){
            z[i]-=z[i*j];

        }
    }
    int e,e2;
    double r=BS(0,1);
    double mx=1;
    for(int i=1;i<=n;i++){
        double p=i*r;
        int p2=p;
        if(p2==p){
            p2--;
        }
        double s=p2;
        double s2=i;
        double q=s/s2;
        if(r-(q)<mx){
            e=p2;
            e2=i;
            mx=r-(q);
        }
    }
    cout<<e<<' '<<e2<<endl;
}

