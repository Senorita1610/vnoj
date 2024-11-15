#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int d[N+5];
long long n,res;
void seive() {
    iota(d,d+N+5,0);
    for (int i=2; i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (i<d[j]) d[j]=i;
    }
}
int main() {
    seive();
    cin>>n;
    for (long long s=1;s*s*s<=n;s++) {
        int t1,t2;
        long long temp=s;
        t1=d[temp];
        temp/=t1;
        if (temp==1) continue;
        t2=d[temp];
        temp/=t2;
        if (t1!=t2&&temp==1&&t1!=1&&t2!=1) {
            res++;
            //cout<<s<<' '<<t1<<' '<<t2<<' '<<s*s*s<<endl;
        }
    }
    cout<<res;
}

