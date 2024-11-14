#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for (int i=b;i>=b,i--)
const int maxn = 200010;
struct Query{
    int l,r,id;
};
struct pt{
    int val,id;
};
Query Q[maxn];
int a[maxn],n,p,m,kq[maxn],m1[maxn],m2[maxn],m3[maxn],r1,r2,d,c,s[maxn];
using namespace std;
map <int, int> mapp[maxn];

bool cmp(Query A, Query B) {
    if ((A.l/p) != (B.l/p)) return A.l/p < B.l/p;
    return A.r < B.r;
}

bool cmp2(pt x, pt y) {
    return x.val < y.val;
}

void push(int j) {
    if (m1[a[j]]==-1) m1[a[j]]=j;
        else m1[a[j]]=min(m1[a[j]],j);
    if (m2[a[j]]==-1) m2[a[j]]=j;
        else m2[a[j]]=max(m2[a[j]],j);
    if ((m1[a[j]]!=-1) && (m2[a[j]]!=-1)) r2=max(r2,m2[a[j]]-m1[a[j]]);
    return;
}

void build() {
	int cnt=1;
	a[0]=1; mapp[1][0]=0;
	For(i,1,n) {
		int x=a[i-1];
		map<int, int>::iterator it=mapp[x].find(-s[i]);
		if (it == mapp[x].end()) x=++cnt;
			else x=a[it->second-1];
		a[i]=x;
		mapp[x][s[i]]=i;
	}
}

int main()
{
    scanf("%d%d",&n,&m);
    int x;
    p = int(sqrt(n));
    For(i,1,n) scanf("%d",&s[i]);
    For(i,1,m) {scanf("%d %d/n",&Q[i].l,&Q[i].r); Q[i].id = i; Q[i].l--;}
    sort(Q+1,Q+m+1,cmp);
    build();
    Q[0].l = 999999999;
    For(i,1,m){
        if (Q[i].l/p!=Q[i-1].l/p){
            For(j,1,n+1){
                m1[j]=-1; m2[j]=-1;
            }
            d=(Q[i].l/p)*p+1, c=min(n,d+p-1);
            r1=0; r2=0;
            For(j,c+1,Q[i].r) push(j);
            For(j,Q[i].l,min(Q[i].r,c)) m3[a[j]]=j;
            For(j,Q[i].l,min(Q[i].r,c)) {
                r1=max(r1,m3[a[j]]-j);
                if (m2[a[j]]!=-1) r1=max(r1,m2[a[j]]-j);
            }
            kq[Q[i].id]=max(r1,r2);
        } else {
            For(j,max(Q[i-1].r+1,c+1),Q[i].r) push(j);
            r1=0;
            For(j,Q[i].l,min(Q[i].r,c)) m3[a[j]]=j;
            For(j,Q[i].l,min(Q[i].r,c)) {
                r1=max(r1,m3[a[j]]-j);
                if (m2[a[j]]!=-1) r1=max(r1,m2[a[j]]-j);
            }
            kq[Q[i].id]=max(r1,r2);
        }
    }
    For(i,1,m) printf("%d\n",kq[i]);
}

