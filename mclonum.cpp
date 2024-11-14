#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long int lli;
int num1[10],num[10];
int num2[10],ln;
string s1,s2,res;
char temp[100];
bool finish,success;
void recure(int ci){
	if(finish) return;
	if(ci==ln){
		return;
	}
	int d=int(s1[ci]-'0');
	for(int i=d;i>=0;i--){
		if(num1[i]&&!(ci==0&&i==0)&&!finish){
			num1[i]--;
			temp[ci]=(i+'0');
			if(i<d){
				for(int k=0;k<=ci;k++){
					printf("%c",temp[k]);
				}
				for(int k=9;k>=0;k--){
					for(int l=1;l<=num1[k];l++){
						printf("%d",k);
					}
				}
				printf("\n");
				finish=true;
				success=true;
				return;
			}
			recure(ci+1);
			num1[i]++;
		}
	}
	return;
}
void recure1(int ci){
	if(finish) return;
	if(ci==ln){
		temp[ci]='\0';
		if(strcmp(temp,s1.c_str())==0){
			printf("%s\n",temp);
			success=true;
		}
		return;
	}
	int d=int(s1[ci]-'0');
	for(int i=d;i<=9;i++){
		if(num2[i]&&!(ci==0&&i==0)&&!finish){
			num2[i]--;
			temp[ci]=(i+'0');
			if(i>d){
				for(int k=0;k<=ci;k++){
					printf("%c",temp[k]);
				}
				for(int k=0;k<=9;k++){
					for(int l=1;l<=num2[k];l++){
						printf("%d",k);
					}
				}
				printf("\n");
				finish=true;
				success=true;
				return;
			}
			recure1(ci+1);
			num2[i]++;
		}
	}
}
int main(){
	bool is;
	int d;
	while(cin>>s1>>s2){
		ln=s1.length();
		res="";
		for(int i=0;i<=9;i++){
			num1[i]=num2[i]=num[i]=0;
		}
		for(int i=0;i<ln;i++){
			d=int(s2[i]-'0');
			num1[d]++;
			num2[d]++;
			d=int(s1[i]-'0');
			num[d]++;
		}
		success=false;
		finish=false;
		strcpy(temp,"");
		success=false;
		bool ok=true;
		for(int i=0;i<=9;i++)
		if(num1[i]!=num[i]){
			ok=false;
			break;
		}
		if(ok)
		cout<<s1<<endl;
		else{
			recure1(0);
			if(!success) printf("0\n");
		}
		finish=false;
		strcpy(temp,"");
		success=false;
		int maxd;
		for(int i=9;i>=0;i--){
			if(num[i]){
				maxd=i;
				break;
			}
		}
		ok=false;
		for(int i=0;i<=9;i++){
			if(num1[i]&&i<maxd){
				ok=true;
				break;
			}
		}
		if(!ok) printf("0\n");
		else{
			success=false;
			recure(0);
			if(!success) printf("0\n");
		}
	}
	return 0;
}

