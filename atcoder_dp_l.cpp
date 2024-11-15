#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const int MAXN=2e5;
long long b,s,t,a[MAXN],seq[MAXN],N,l=1,r=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>N;
	t=s=b=0;
	for(int i=1;i<=N;i++){
		cin>>a[i];
		t++;
		seq[t]=a[i];
		while(t>2 && seq[t-1]>seq[t-2]&&seq[t-1]>seq[t]){
			seq[t-2]=seq[t]+seq[t-2]-seq[t-1];
			t-=2;
		}
	}
	r=t;
	for(int i=1;i<=t;i++){
		if(seq[l]>seq[r]){
			b+=(long long)pow(-1,i+1)*seq[l++];
		}
		else{
			b+=(long long)pow(-1,i+1)*seq[r--];
		}
	}
	cout<<b<<endl;
	return 0;
}

