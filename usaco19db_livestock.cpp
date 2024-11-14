#include<bits/stdc++.h>
using namespace std;
string s[10]={"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"},sen[10][10];
int n,cnt,flag;
map<string,int>m;
int main(){
	for(int i=0;i<8;i++){
		m[s[i]]=i;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<6;j++){
			cin>>sen[i][j];
		}
	}
	while(cnt<=43200){
		flag=0;
		cnt++;
		for(int i=0;i<n;i++){
			if(abs(m[sen[i][0]]-m[sen[i][5]])!=1){
				flag=1;
				break;
			}
		}
		if(!flag){
			break;
		}
		next_permutation(s,s+8);
		for(int i=0;i<8;i++){
			m[s[i]]=i;
		}
	}
	for(int i=0;i<8;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}

