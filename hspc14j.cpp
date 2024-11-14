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
using namespace std;
int p[1010],cnt,n,k;

int main() {
    while (scanf("%d %d\n",&n,&k)!=-1) {
        memset(p,0,sizeof(p));
        cnt=0;
        For(i,2,n)
        if (p[i]==0)
            For(j,i,n) if ((j%i==0)&&(p[j]==0)) p[j]=++cnt;
        For(i,2,n) if (p[i]==k) printf("%d\n",i);
    }
}

