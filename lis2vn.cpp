#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef map<int,int>mp;
const int MX=1e5+5;
mp M[MX];
bool comp(pii p,mp &_M){
	mp::iterator it=_M.lower_bound(p.first);
	return !(it!=_M.begin()&&(--it)->second<p.second);
}
void add(pii p,int pos){
	mp::iterator it=M[pos].lower_bound(p.first),itr=it;
	if(it!=M[pos].end()&&p.first==it->first&&p.second>it->second) return;
	if(it!=M[pos].begin()&&p.second>(--it)->second) return;
	it=itr;
	for(;it!=M[pos].end()&&it->second>=p.second;it++);
	M[pos].erase(itr,it);
	M[pos][p.first]=p.second;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,x,y,len=0,pos=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		pos=upper_bound(M,M+len,pii(x,y),comp)-M;
		if(len==pos) len++;
		add(pii(x,y),pos);
	}
	cout<<len<<endl;
	return 0;
}

