#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool p[N+5];
int cnt[N+5];
int c[8][N+5];
int q;
int a,b,k;
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (int i=2;i<=N;i++) {
        if (p[i]) {
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
void preprocess() {
    seive();
    for (int i=1;i<=N;i++) {
        if (p[i])
            for (int j=i;j<=N;j+=i) cnt[j]++;
    }
    for (int i=1;i<=7;i++)
        for (int j=1;j<=N;j++)
            c[i][j]=c[i][j-1]+(cnt[j]==i);
}
int main() {
    preprocess();
    cin>>q;
    while (q--) {
        cin>>a>>b>>k;
        cout<<c[k][b]-c[k][a-1]<<endl;
    }
}

