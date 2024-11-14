#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ld long double
#define pb push_back
#define reset(f,x) memset(f,x,sizeof(f))
#define sz(s) int(s.size())
#define N 366
#define NN 7671196

const int ke[9][5] = {
    {0,1,2,3,6}, {0,1,2,4,7}, {0,1,2,5,8}, {0,3,6,4,5}, {1,3,4,5,7}, {2,5,8,3,4}, {0,3,6,7,8}, {1,4,7,3,5}, {2,5,8,6,7}
};

const int phu[9][4] = {
    {0,1,4,5}, {1,2,5,6}, {2,3,6,7}, {4,5,8,9}, {5,6,9,10}, {6,7,10,11}, {8,9,12,13}, {9,10,13,14}, {10,11,14,15}
};

int n,c[N][16],qi[NN],qu[NN],q1[NN],q2[NN],q3[NN],q4[NN],lef,righ,trace[NN],fes[N][16];
bool dd[N][9][7][7][7][7];

void push(int i,int u,int t1,int t2,int t3,int t4) {
    if (dd[i][u][t1][t2][t3][t4]) {
        dd[i][u][t1][t2][t3][t4] = false;
        qi[++righ] = i; q1[righ] = t1; q2[righ] = t2; q3[righ] = t3; q4[righ] = t4;
        trace[righ] = lef;
        qu[righ] = u;
    }
}

bool check(int i,int u) {
    For(j,0,3) if (c[i][phu[u][j]]) return false;
    return true;
}

void to(int i,int u) {
    For(j,0,3) fes[i][phu[u][j]] = 1;
}

void check() {
    For(i,0,15) {
        For(j,0,n-6) {
            int s = 0;
            For(t,j,j+6) s += fes[t][i];
            if (s == 0) printf("%d %d\n",i,j);
        }
    }
}

void out() {
    For(day,1,n) {
        For(i,0,15) {
            printf("%d ",fes[day][i]);
            if (i % 4 == 3) printf("\n");
        }
    }
}

void solve() {
    reset(dd,true);
    lef = 0; righ = 0;
    push(1,4,1,1,1,1);
    while (lef < righ) {
        int i = qi[++lef], t1 = q1[lef], t2 = q2[lef], t3 = q3[lef], t4 = q4[lef], u = qu[lef];
        if (i == n) {
        	cout << 1 << "\n";
        	//int x = lef;
        	//while (x) {
          // //     printf("%d %d %d %d %d %d\n",qi[x],qu[x],q1[x],q2[x],q3[x],q4[x]);
           //     to(qi[x],qu[x]);
          //      x = trace[x];
        //	}
        	//check();
              //out();
        	return;
		}
        For(j,0,4) {
            int v = ke[u][j];
            if (check(i+1,v)) {
                int v1 = t1+1, v2 = t2+1, v3 = t3+1, v4 = t4+1;
                if (v == 0) v1 = 0;
                if (v == 2) v2 = 0;
                if (v == 6) v3 = 0;
                if (v == 8) v4 = 0;
                if (v1 < 7 && v2 < 7 && v3 < 7 && v4 < 7) push(i+1,v,v1,v2,v3,v4);
            }
        }
    }
    cout << 0 << "\n";
}

int main() {
    while (1) {
        scanf("%d",&n);
        if (!n) break;
        For(i,1,n) For(j,0,15) scanf("%d",&c[i][j]);
        solve();
    }
}

