#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<iterator>
#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
//#include<conio.h>
#define ep 0.000000001
#define maxn 10011
#define oo 1111111
#define modunlo 1000000000
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
double const PI=4*atan(1);

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

map<long long,long long> M;

long long xuly(long long n){
      if(M[n]>0) return M[n];
      if(n==3) return M[3] = 192;
      if(n==1) return M[1] = 8;
      if(n==2) return M[2] = 40;
      if(n%2==0){
            long long u = xuly(n/2);
            long long v = xuly(n/2-1);
            return M[n] = (u*u/2+2*v*v)%modunlo;
      }
      else{
            long long u = xuly((n+1)/2);
            long long v = xuly((n+1)/2-1);
            long long r = xuly((n+1)/2-2);
            return M[n] = (u*v/2+2*v*r)%modunlo;
      }
}

int main(){
      long long n;
      scanf("%lld",&n);
      if(n<=1) printf("0");
      else if(n==2) printf("1");
      else printf("%lld",xuly(n-2));
}

