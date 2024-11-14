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
int ntest,n,res,temp;

void tinh(int a,int b) {
    if (b==1) {
        temp+=a-1;
        return;
    }
    if (a%b==0) {temp=n+1; return;}
    temp+=a/b;
    tinh(b,a%b);
}

int main() {
    scanf("%d",&ntest);
    while (ntest) {
        scanf("%d",&n);
        ntest--;
        res=n-1;
        For(i,1,n-1) {
            temp=0;
            tinh(n,i);
            res=min(res,temp);
        }
        printf("%d\n",res);
    }
}

