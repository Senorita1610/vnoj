#include <cstdio>

const int MAXM=55;
const int MAXN=27;

inline int unCode(char c){
	return (c-'A'+1);
}

char input[11];
int N=26, M;
int Kill[MAXN];
int F[MAXN<<1];
int Vcnt;
int P[2][MAXN], Sour, Sink;
int Ans;

int Find(int a){
	if(F[F[a]]!=F[a])	F[a]=Find(F[a]);
	return F[a];
}

void Merge(int a, int b){
	a=Find(a);b=Find(b);
	if(a!=b)	F[a]=b;
}

struct Query{
	int p[2];
	int to, c;
} Q[MAXM];

bool Test(){
	
	bool ret=true;
	
	Vcnt=0;
	for(int i=1;i<=N;++i){
		if(Kill[i])	continue;
		P[0][i]=++Vcnt;
		P[1][i]=++Vcnt;
	}
	Sour=++Vcnt;Sink=++Vcnt;
	
	for(int i=1;i<=Vcnt;++i)	F[i]=i;
	
	for(int i=1, c;i<=M && ret;++i){
		c=0;
		if(!Kill[Q[i].p[0]])	++c;
		if(!Kill[Q[i].p[1]])	++c;
		if(Q[i].c>c)	{ret=false;continue;}
		if(c==0)	continue;
		if(Q[i].c==0){
			if(!Kill[Q[i].p[0]]){
				Merge(P[!Q[i].to][Q[i].p[0]], Sour);
				Merge(P[Q[i].to][Q[i].p[0]], Sink);
			}
			if(!Kill[Q[i].p[1]]){
				Merge(P[!Q[i].to][Q[i].p[1]], Sour);
				Merge(P[Q[i].to][Q[i].p[1]], Sink);
			}
			continue;
		}
		if(Q[i].c==c){
			if(!Kill[Q[i].p[0]]){
				Merge(P[!Q[i].to][Q[i].p[0]], Sink);
				Merge(P[Q[i].to][Q[i].p[0]], Sour);
			}
			if(!Kill[Q[i].p[1]]){
				Merge(P[!Q[i].to][Q[i].p[1]], Sink);
				Merge(P[Q[i].to][Q[i].p[1]], Sour);
			}
			continue;
		}
		Merge(P[Q[i].to][Q[i].p[0]], P[!Q[i].to][Q[i].p[1]]);
		Merge(P[!Q[i].to][Q[i].p[0]], P[Q[i].to][Q[i].p[1]]);
	}
	
	for(int i=1;i<=N && ret;++i){
		if(Kill[i])	continue;
		if(Find(P[0][i])==Find(P[1][i]))	ret=false;
	}
	
	return ret;
}

int main(){
	
	scanf("%d", &M);
	for(int i=1;i<=M;++i){
		scanf("%s", input);
		Q[i].p[0]=unCode(input[0]);
		Q[i].p[1]=unCode(input[1]);
		scanf("%d%d", &Q[i].to, &Q[i].c);--Q[i].to;
	}
	
	for(int i=1;i<=N;++i){
		for(int j=i+1;j<=N;++j){
			for(int k=j+1;k<=N;++k){
				Kill[i]=Kill[j]=Kill[k]=true;
				
				if(Test())	++Ans;
				
				Kill[i]=Kill[j]=Kill[k]=false;
			}
		}
	}
	
	printf("%d\n", Ans);
	
	return 0;
}

