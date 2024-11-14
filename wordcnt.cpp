#include<bits/stdc++.h>
using namespace std;
int main(){
	int tests;
	cin>>tests>>ws;
	while(tests--){
		string line,s;
		getline(cin,line);
		stringstream in(line);
		int mx=0,cnt=0,oldsize=0;
		while(in>>s){
			if(s.size()==oldsize) cnt++;
			else cnt=1;
			oldsize=s.size();
			mx=max(mx,cnt);
		}
		cout<<mx<<endl;
	}
}

