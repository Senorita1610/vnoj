#include<stdio.h>
#include<string.h>

char name[1001][1024],word[101][32];
int n,m,len;

bool Appered(const char*,const char*);

int main(void){
	register int i,j,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s",name[i]);
		for(j=0,len=strlen(name[i]);j<len;j++)
			if('A'<=name[i][j]&&name[i][j]<='Z')
				name[i][j]+=32;
	}
	for(i=1;i<=m;i++){
		scanf("%s",word[i]);
		for(j=0,len=strlen(word[i]);j<len;j++)
			if('A'<=word[i][j]&&word[i][j]<='Z')
				word[i][j]+=32;
	}
	for(i=1;i<=n;i++){
		ans=0;
		for(j=1;j<=m;j++)
			if(Appered(name[i],word[j]))
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}

bool Appered(const char *Name,const char *Word){
	int i,j,lenN=strlen(Name),lenW=strlen(Word);
	for(i=j=0;i<lenN;i++){
		if(Name[i]==Word[j])
			j++;
		if(j==lenW)
			return true;
	}
	return false;
}

