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
int n,l,c[10],d[10];
const int a[10] = {0,9,98,987,9876,98765,987654,9876543,98765432,987654321};
const int b[10] = {1,12,123,1234,12345,123456,1234567,12345678,123456789,0};
bool fr[10];
bool found;

void ql(int i,int ok) {
    if (found) return;
    if (i>l) {
        if (ok==1) {found=true; For(j,1,l) printf("%d",d[j]); printf("\n");}
        return;
    }
    int dau;
    if (ok) dau=1; else dau=c[i];
    For(j,dau,9) if (fr[j]) {
        int ok2;
        if ((ok==1)||(j>c[i])) ok2=1; else ok2=0;
        fr[j]=false;
        d[i]=j;
        ql(i+1,ok2);
        fr[j]=true;
    }
}

int main() {
    while (scanf("%d\n",&n)!=-1) {
        int x=n;
        l=0;
        while (x) {l++; x/=10;}
        if (n>=a[l]) printf("%d\n",b[l]); else {
            x=n;
            int le=l;
            while (x) {c[le]=x%10; le--; x/=10;}
            memset(fr,true,sizeof(fr));
            fr[0]=false;
            found=false;
            ql(1,0);
        }
    }
}

