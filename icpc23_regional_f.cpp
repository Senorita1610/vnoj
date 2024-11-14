#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s,s2;
		cin>>s>>s2;
		multiset<char>st,st2,st3,st4;
		for(int i=0;i<s.length();i++){
			if(i%2==0){
				st.insert(s[i]);
				st2.insert(s2[i]);
			}
			else{
				st3.insert(s[i]);
				st4.insert(s2[i]);
			}
		}
		if(st==st2&&st3==st4&&s.length()==s2.length()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

