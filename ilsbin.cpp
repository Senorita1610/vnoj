#include<bits/stdc++.h>
using namespace std;
struct hzy{
	int x,y,z;
}a[200001];
int f[200001],n,m,b[200001],l;
int zuxian(int k){
	return f[k]==k?k:f[k]=zuxian(f[k]);
}
void hebing(int x,int y){
	int x1=zuxian(x);
	int x2=zuxian(y);
	if(x1!=x2){
		f[x1]=x2;
	}
}
int main() {
	cin>>n>>m;
	string ch;
	for(int i=1; i<=m; i++) {
		cin>>a[i].x>>a[i].y>>ch;
		a[i].x--;
		if(ch[0]=='o') {
			a[i].z=1;
		} else {
			a[i].z=0;
		}
		b[++l]=a[i].x;
		b[++l]=a[i].y;
	}
	sort(b+1,b+l+1);
	l=unique(b+1,b+l+1)-b-1;
	for(int i=1;i<=l*2;i++){
		f[i]=i;
	}
	for(int i=1; i<=m; i++) {
		a[i].x=lower_bound(b+1,b+l+1,a[i].x)-b;
		a[i].y=lower_bound(b+1,b+l+1,a[i].y)-b;
		if(a[i].z==0){
			if(zuxian(a[i].x)==zuxian(a[i].y+l)){
				cout<<i-1;
				return 0;
			}
			else{
				hebing(a[i].x,a[i].y);
				hebing(a[i].x+l,a[i].y+l);
			}
		}
		else{
			if(zuxian(a[i].x)==zuxian(a[i].y)){
				cout<<i-1;
				return 0;
			}
			else{
				hebing(a[i].x,a[i].y+l);
				hebing(a[i].x+l,a[i].y);
			}
		}
	}
	cout<<m;
	return 0;
}

