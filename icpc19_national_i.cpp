#include<bits/stdc++.h>
using namespace std;
char s[1000008];
double a,b;
int i;
int main(){
	for(scanf("%s",s),i=strlen(s);i--;s[i]=='T'?a+=b:(s[i]=='H'?(a+=1,b+=2):(a+=(b+1)*0.5,b+=1)));
	printf("%lf\n",a),exit(0);
}

