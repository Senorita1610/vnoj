#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int L=19,N=1<<(L-1);
char _s[L],_rs[L];
char _t[L],_rt[L];
bool _flg[128];
int visit[N];
int _pre[L][L][L];
int lenS,lenT;
int KMP(char p[],char t[],int pre[]){
	int res=0;
	for(int i=0,j=-1;0!=t[i];i++){
		for(;-1<j&&p[j+1]!=t[i];j=pre[j]);
		if(p[j+1]==t[i])++j;
		if(res<j+1) res=j+1;
		if(0==p[res]) break;
	}
	return res;
}
void decode(int state, char s[],char rs[]){
	int i;
	for(i=0;i<lenT;i++){
		if(state&(1<<i)) s[i]=_t[i];
		else s[i]='0';
	}
	rs[lenT]=0;
	reverse_copy(s,s+lenT,rs);
	s[lenT]=0;
}
int DFS(int d,int state){
	if(visit[state]!=-1) return visit[state];
	char t[L],rt[L];
	decode(state,t,rt);
	int prelen=0;
	int bst=lenT;
	for(int i=0,j;0!=t[i];i++){
		for(j=i;'0'==t[j];j++);
		if(j==i){
			prelen=0;
			continue;
		}
		char ch=_t[j];
		_t[j]=0;
		int *pre=_pre[i][j];
		int len=KMP(_t+i,_s,pre);
		len=max(len,KMP(_t+i,_rs,pre));
		len=max(len,KMP(_t+i,t,pre));
		len=max(len,KMP(_t+i,rt,pre));
		_t[j]=ch;
		if(prelen<=len){
			int nxt=state|(((1<<(i+len))-1)^((1<<i)-1));
			int ret=DFS(d+1,nxt);
			bst=min(bst,ret+1);
		}
		prelen=max(prelen-1,len);
	}
	return visit[state]=bst;
}
void CalPre(char p[],int pre[]){
	int i,j;
	pre[0]=-1;
	for(i=1,j=-1;p[i];i++){
		for(;j>-1&&p[j+1]!=p[i];j=pre[j]);
		if(p[j+1]==p[i]) j++;
		pre[i]=j;
	}
}
void InitPre(){
	int i,j;
	char ch;
	for(i=0;_t[i];i++) for(j=i+1;_t[j-1];j++){
		ch=_t[j];
		_t[j]=0;
		CalPre(_t+i,_pre[i][j]);
		_t[j]=ch;
	}
}
void Init(){
	lenS=strlen(_s);
	lenT=strlen(_t);
	reverse_copy(_s,_s+lenS,_rs);
	_rs[lenS]=0;
	reverse_copy(_t,_t+lenT,_rt);
	_rt[lenT]=0;
	memset(visit,-1,sizeof(visit));
	visit[(1<<lenT)-1]=0;
	InitPre();
}
int OK(char s[],char t[]){
	int lenS=strlen(s);
	int lenT=strlen(t);
	int i,j;
	for(i=0;i<lenT;i++){
		for(j=0;j<lenS;j++) if(s[j]==t[i]) break;
		if(j==lenS) return 1;
	}
	return 0;
}
int C;
int main(){
	for(scanf("%d",&C);C--;){
		scanf("%s%s",_s,_t);
		if(OK(_s,_t)){
			puts("impossible");
			continue;
		}
		Init();
		printf("%d\n",DFS(0,0));
	}
	return 0;
}

