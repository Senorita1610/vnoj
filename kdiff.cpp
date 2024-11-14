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

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ll long long
#define ld long double
#define pb push_back
#define sz(s) int(s.size())
#define N 300010

int n,k,a[N],f[N],g[N],p1[N],top1,bot1,p2[N],top2,bot2,res;

void solve() {
    if (n==1) {
        printf("1"); return;
    }
    top1=1; bot1=1; f[1]=1; p1[1]=1;
    top2=1; bot2=1; p2[1]=1;
    int j=1;
    For(i,2,n) {
        while (top1>=bot1 && a[i]<=a[p1[top1]]) top1--;
        while (top2>=bot2 && a[i]>=a[p2[top2]]) top2--;
        p1[++top1]=i; p2[++top2]=i;
        while (1) {
            if (a[p2[bot2]]-a[p1[bot1]]>k) {
                while (top1>=bot1 && p1[bot1]<=j) bot1++;
                while (top2>=bot2 && p2[bot2]<=j) bot2++;
                j++;
            } else break;
        }
        f[i]=max(f[i-1],i-j+1);
    }
    top1=1; top2=1; bot1=1; bot2=1; g[n]=1;
    p1[1]=n; p2[1]=n; j=n;
    res=max(res,1+f[n-1]);
    Ford(i,n-1,2) {
        while (top1>=bot1 && a[i]<=a[p1[top1]]) top1--;
        while (top2>=bot2 && a[i]>=a[p2[top2]]) top2--;
        p1[++top1]=i; p2[++top2]=i;
        while (1) {
            if (a[p2[bot2]]-a[p1[bot1]]>k) {
                while (top1>=bot1 && p1[bot1]>=j) bot1++;
                while (top2>=bot2 && p2[bot2]>=j) bot2++;
                j--;
            } else break;
        }
        g[i]=max(g[i+1],j-i+1);
        res=max(res,g[i]+f[i-1]);
    }
    printf("%d",res);
}

int main() {
    scanf("%d%d",&n,&k);
    For(i,1,n) scanf("%d\n",&a[i]);
    solve();
}

