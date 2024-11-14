#include <cstdio>
using namespace std;

char a[10010];
int dem[26], n;
int sl5[10010], sl2[10010];

int main() {
    gets(a);
    for(int i=0;a[i]!=0;++i) ++dem[a[i]-'a'], ++n;
    #define doit(A,B) { for(int i=1;B*i<=n;++i) A[B*i] = A[i] + 1; for(int i=1;i<=n;++i) A[i] += A[i-1]; }
    doit(sl5,5)
    doit(sl2,2)
    #define get(r,A) { r = A[n]; for(int i=0;i<26;++i) r -= A[dem[i]]; }
    int r2, r5;
    get(r2,sl2)
    get(r5,sl5)
    printf("%d\n", r2<r5?r2:r5);
    return 0;   
}

