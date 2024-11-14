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
int a,b,c;

int main() {
    while (scanf("%d%d%d\n",&a,&b,&c)!=-1) {
        printf("%d\n",max(b-a-1,c-b-1));
    }
}

