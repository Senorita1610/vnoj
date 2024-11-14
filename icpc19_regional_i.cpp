#include<iostream>
int ans[1005];
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;(1<<i)<=n;i++){
		int s=0;
		for(int j=1;j<=n;j++){
			if(j&(1<<i)) ++s;
		}
		cout<<"ASK "<<s<<" ";
		for(int j=1;j<=n;j++){
			if(j&(1<<i)) cout<<j<<" ";
		}
		cout<<endl;
		while(1){
			int a;
			char c;
			scanf("%d%c",&a,&c);
			ans[a]+=(1<<i);
			if(c=='\n'||c=='\r') break;
		}
	}
	cout<<"ANSWER ";
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

