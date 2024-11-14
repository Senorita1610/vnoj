#include<iomanip>
#include<iostream>
#include<map>
using namespace std;
int n,a,b,c,x;
map<int,int>res,ri;
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		res.clear();
		ri.clear();
		for(int i=0,num=1;num<=n;i++,num*=10){
			if(n%num%2!=0) break;
			a=n/num/11;
			b=n/num%11;
			c=n%num/2;
			if(b<=9){
				x=(a*10+b)*num+c;
				if(a+b) res[x]=a*num+c;
				ri[x]=i;
			}
			c=(n%num+num)/2;
			b=n/num%11-1;
			if(b>=0&&c){
				x=(a*10+b)*num+c;
				if(a+b) res[x]=a*num+c;
				ri[x]=i;
			}
		}
		cout<<res.size()<<endl;
		for(map<int,int>::iterator it=res.begin();it!=res.end();it++){
			cout<<it->first<<" + "<<setw(ri[it->first])<<setfill('0')<<it->second<<" = "<<n<<endl;
		}
	}
	return 0;
}

