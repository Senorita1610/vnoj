#include<math.h>
#include<stdio.h>
#include<string.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a>b?b:a;
}
int main(){
	int t,i,f;
	char s1[100],s2[100],s3[100];
	scanf("%d",&t);
	while(t--){
		f=1;
		scanf("%s",s1);
		scanf("%s",s3);
		scanf("%s",s2);
		for(i=0;i<strlen(s2);i++){
			if(s1[i]!=s2[i]){
				f=0;
				break;
			}
		}
		for(i=strlen(s3)-1;i>=0;i--){
			if(s1[i+strlen(s2)]!=s3[i]){
				f=0;
				break;
			}
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

