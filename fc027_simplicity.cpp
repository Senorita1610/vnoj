#include<bits/stdc++.h>
using namespace std;
map<char,int> c;
int cnt,res;
vector<int>v;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    for (auto i:s) {
    	c[i]++;
    	cnt+=(c[i]==1);
    }
    if (cnt<=2) {
    	cout<<0;
    	return 0;
    }
    for (auto i=c.begin();i!=c.end();i++) v.push_back(i->second);
    sort(v.begin(),v.end());
    for (int i=0;i<cnt-2;i++) res+=v[i];
    cout<<res;
}

