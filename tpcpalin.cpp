#include<iostream>
using namespace std;
const int N=5e2+5,MOD=3210121;
string str1,str2;
int dp[N][N][2]={};
int len,nowx,nowy,flag=0,now;
int main(){
	cin>>str1>>str2;
	len=str1.size()+str2.size();
	str1=" "+str1,str2=" "+str2;
	for(int i=0;i<=len/2;i++) for(int j=0;j<=len/2;j++) dp[i][j][0]=1;
	for(int i=(len/2)-1;i>=0;i--,flag=(1-flag)){
		for(int j=0;j<=i;j++){
			nowx=j+1,nowy=i-j+1;
			for(int k=0;k<=i;k++){
				now=0;
				if(nowx<str1.size()-1-k&&str1[nowx]==str1[str1.size()-1-k]) now+=dp[j+1][k+1][flag];
				if(nowy<str2.size()-1-i+k&&str2[nowy]==str2[str2.size()-1-i+k]) now+=dp[j][k][flag];
				if(nowx<=str1.size()-1-k&&nowy<=str2.size()-1-i+k){
					if(str1[nowx]==str2[str2.size()-1-i+k]) now+=dp[j+1][k][flag];
					if(str2[nowy]==str1[str1.size()-1-k]) now+=dp[j][k+1][flag];
				}
				dp[j][k][flag^1]=now%MOD;
			}
		}
	}
	cout<<dp[0][0][flag]<<endl;
}

