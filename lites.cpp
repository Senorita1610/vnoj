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
#define ep 0.000001
#define maxn 100011
#define mod 1000000000
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define fi first 
#define se second

double const PI=4*atan(1);
double const oo = 1e19;

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

struct tree{
    int number, change;
    tree(){};
    tree(int _number, int _change){ number = _number, change = _change;}
};

tree empty = tree(0,0);

int n, m, u, v, chiso;
tree f[maxn * 4];

void update(int l, int r, int i){

    if(u > r || v < l){
        if(f[i].change) f[i].number = r - l + 1 - f[i].number;
        f[i + i].change ^= f[i].change;
        f[i + i + 1].change ^= f[i].change;
        f[i].change = 0; 
    return;
    }
    if(u <= l && v >= r){ 
        f[i].change = 1 - f[i].change;
        if(f[i].change) f[i].number = r - l + 1 - f[i].number;
        f[i + i].change ^= f[i].change;
        f[i + i + 1].change ^= f[i].change;
        f[i].change = 0;
        return;
    }
    int mid = (l + r) / 2;
    f[i + i].change ^= f[i].change;
    f[i + i + 1].change ^= f[i].change;
    f[i].change = 0;
    update(l, mid, i + i);
    update(mid + 1, r, i + i + 1);
    f[i].number = f[i + i].number + f[i + i + 1].number;
}

int get(int l, int r,int i){
    if(u > r || v < l) return 0;
    if(u <= l && v >= r){
        if(f[i].change) return r - l + 1 - f[i].number;
        return f[i].number;
    }
    int mid = (l + r) / 2;
    f[i + i].change ^= f[i].change;
    f[i + i + 1].change ^= f[i].change;
    if(f[i].change) f[i].number = r - l + 1 - f[i].number;
    f[i].change = 0;
    return get(l, mid, i + i) + get(mid + 1, r, i + i + 1);
}

int main(){
   // freopen("input.in","r",stdin); 
   // freopen("output.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i = 1; i < 4 * n; i++) {
        f[i] = empty;
    }
    //printf("%d.......\n",f[1].length);
    for(int i = 0; i < m; i++){
      //  printf("**%d\n",i);
        scanf("%d %d %d",&chiso,&u,&v);
        if(chiso == 0){ update(1, n, 1);}
        else printf("%d\n",get(1, n, 1));
    }
     // getch();
}

