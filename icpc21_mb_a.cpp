#include <bits/stdc++.h>

using namespace std;


int main () {
    string s;
	cin >> s;
	int n = s.size();
	string x = "";
	int d = 0;
	for(int i=n-3;i<=n-1;i++){
        x+=s[i];
	}
	if(x != ".py"&& x!=".Py"&&x!=".PY"&&x!=".pY"){
        d++;
	}
	for(int i=0;i<n;i++){
        if(s[i]==' '){
            d++;
        }
	}
	int a = 0;
	for(int i=0;i<n;i++){
        if(s[i]=='.'){
            a++;
        }
	}
	if(a!=1){
        d++;
	}
	for(int i=0;i<n;i++){
        if(s[i]<'A'&&s[i]>'Z'&&s[i]<'a'&&s[i]>'z'&&s[i]!='.'&&s[i]!='_'){
            d++;
        }
	}
	if(d){
        cout<<"no"<<endl;
	}
	else{
        cout<<"yes"<<endl;
	}
}

