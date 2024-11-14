#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=20;
int n;
int suma[1<<N],sumb[1<<N];
pair<int,int>mem[1<<N];
int main(){
	scanf("%d",&n);
	int fulla=0,fullb=0;
	for(int i=0;i<n;i++){
		scanf("%d",&suma[1<<i]);
		fulla+=suma[1<<i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",&sumb[1<<i]);
		fullb+=sumb[1<<i];
	}
	for(int i=0;i < 1 << n;i++){
		if(i){
			int lb=i & -i;
			suma[i]=suma[i^lb]+suma[lb];
			sumb[i]=sumb[i^lb]+sumb[lb];
		}
	}
	int full=(1<<n)-1;;
	for(int i=0;i < 1 << n;i++){
		mem[i]=make_pair(suma[i],sumb[full-i]);
	}
	sort(mem,mem+(1<<n));
	vector<pair<int,int>>stack;
	for(int i=0;i<1<<n;i++){
		while(stack.size()&&stack.back().second<=mem[i].second){
			stack.pop_back();
		}
		stack.push_back(mem[i]);
	}
	long long a=fulla,b=fullb;
	for(int i=0;i+1<(int)stack.size();i++){
		long long ta=stack[i].first+1,tb=stack[i+1].second+1;
		if(ta+tb<a+b){
			a=ta,b=tb;
		}
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}

