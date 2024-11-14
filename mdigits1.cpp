#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<ctime>
#include<string.h>
using namespace std;
const double PI=acos(-1.0);
const double eps=1E-7;
const int oo=123456789;
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
typedef pair<int,int>ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a),0,sizeof(a))
#define MM(a,b) memcpy(a,b,sizeof(a))
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
const int maxN=1000000;
int father[maxN],fr[maxN];
int q[maxN];
int st,n;
char ans[maxN],tmp[maxN];
int a1,t1;
bool work(){
	memset(father,-1,4*n);
	int clo=0,open=0;
	int a[10],m=0;
	FOR(k,10) if(two(k)&st) a[m++]=k;
	FOR(i,m){
		if(a[i]!=0&&father[a[i]%n]==-1){
			father[a[i]%n]=-2;
			fr[a[i]%n]=a[i];
			q[open++]=a[i]%n;
		}
	}
	int x,y;
	while(father[0]==-1&&(clo<open)){
		x=q[clo++];
		FOR(i,m){
			y=(x*10+a[i])%n;
			if(father[y]==-1){
				father[y]=x;
				fr[y]=a[i];
				q[open++]=y;
			}
		}
	}
	if(father[0]!=-1) return true;
	return false;
}
void outans(int x){
	while(1>0){
		tmp[t1++]=fr[x]+'0';
		if(father[x]!=-2) x=father[x];
		else break;
	}
}
void update(){
	bool better=false;
	if(a1==0) better=true;
	else if(t1<a1) better=true;
	else if(a1==t1){
		for(int i=a1-1;i>=0;i--) if(tmp[i]<ans[i]){
			better=true;
			break;
		}
		else if(tmp[i]>ans[i]) break;
	}
	if(better){
		a1=t1;
		FOR(i,a1) ans[i]=tmp[i];
	}
}
int main(){
	while(scanf("%d",&n)){
		if(n==0) break;
		for(int i=1;i<=10;i++){
			a1=0;
			for(st=1;st<(1<<10);st++){
				int num=0;
				FOR(k,10) if(two(k)&st) num++;
				if(num!=i) continue;
				if(work()){
					t1=0;
					outans(0);
					update();
				}
			}
			if(a1!=0){
				for(int k=a1-1;k>=0;k--) printf("%c",ans[k]);
				puts("");
				break;
			}
		}
	}
}

