#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
 
const int Nmax=2010;
const ull P=998244353, Q=1e11+19;
int N, M;
bool A[Nmax][Nmax];
ull Pm[Nmax], Qm[Nmax], Pi, Qi, Pim[Nmax], Qim[Nmax], H[Nmax][Nmax];
pair<int, int> X[Nmax*Nmax];
 
ull Pow(ull a, ull b) {
    if(b==0) return 1;
    ull tmp=Pow(a, b/2);
    tmp*=tmp;
    if(b%2) tmp*=a;
    return tmp;
}
 
ull Hash2D(int sy, int sx, int ey, int ex) {
    ull res=H[ey][ex]-H[sy-1][ex]-H[ey][sx-1]+H[sy-1][sx-1];
    return res*Pim[sx-1]*Qim[sy-1];
}
 
ull Hash1D(int y, int sx, int ex) {
    return Hash2D(y, sx, y, ex);
}
 
bool f(int ay, int ax, int by, int bx) {
    int h=0, w=0;
    for(int s=1, e=N-1; s<=e;) {
        int m=(s+e)/2;
        if(Hash2D(ay, ax, ay+m-1, ax+M-1)==Hash2D(by, bx, by+m-1, bx+M-1)) h=m, s=m+1;
        else e=m-1;
    }
    for(int s=1, e=M; s<=e;) {
        int m=(s+e)/2;
        if(Hash1D(ay+h, ax, ax+m-1)==Hash1D(by+h, bx, bx+m-1)) w=m, s=m+1;
        else e=m-1;
    }
    if(h==N-1 && w==M) return false;
    if(w==M) return A[ay+h][ax]<A[by+h][bx];
    return A[ay+h][ax+w]<A[by+h][bx+w];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        string S; cin>>S;
        for(int j=1; j<=M; j++) A[i][j]=(S[j-1]=='.');
    }
    for(int i=1; i<=N; i++) {
        for(int j=M+1; j<=2*M; j++) A[i][j]=A[i][j-M];
    }
    for(int i=N+1; i<=2*N; i++) {
        for(int j=1; j<=2*M; j++) A[i][j]=A[i-N][j];
    }
    Pm[0]=Qm[0]=1;
    for(int i=1; i<=2*max(N, M); i++) {
        Pm[i]=Pm[i-1]*P;
        Qm[i]=Qm[i-1]*Q;
    }
    Pi=Pow(P, ULLONG_MAX); Qi=Pow(Q, ULLONG_MAX);
    Pim[0]=Qim[0]=1;
    for(int i=1; i<=2*max(N, M); i++) {
        Pim[i]=Pim[i-1]*Pi;
        Qim[i]=Qim[i-1]*Qi;
    }
    for(int i=1; i<=2*N; i++) {
        for(int j=1; j<=2*M; j++) {
            H[i][j]=H[i][j-1]+H[i-1][j]-H[i-1][j-1]+A[i][j]*Pm[j-1]*Qm[i-1];
        }
    }
    int x=1, y=1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(f(i, j, x, y)) x=i, y=j;
        }
    }
    for(int i=x; i<=x+N-1; i++) {
        for(int j=y; j<=y+M-1; j++) {
            if(A[i][j]) cout<<".";
            else cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}

