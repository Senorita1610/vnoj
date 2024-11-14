#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ll long long
#define pb push_back
#define N 3010
using namespace std;
int n;
ll dp[N][4][3];
bool check[N][4][3];

ll tinh(int i, int x, int y) {
    ll res=0;
    if (i>n) return 1;
    if (check[i][x][y]) return dp[i][x][y];
    res += tinh(i+1,0,y);
    if (y==0) res+= tinh(i+1,0,1);
    if (x<2) res+= tinh(i+1,x+1,y);
    check[i][x][y]=true;
    dp[i][x][y]=res;
    return res;
}

int main() {
    while (scanf("%d\n",&n)!=-1) {
        memset(check,false,sizeof(check));
        printf("%lld\n",tinh(1,0,0));
    }
}

