#include<bits/stdc++.h>
using namespace std;
bool t[1000009];
int a[1000009];
int main(){
	int n;
	int ma;
	int u;
	int x,y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++){
		t[(a[i]-i+n)%n]=1;
	}
	ma=0;
	u=0;
	for(int i=0;i<n;i++){
		if(t[i]){
			ma=max(ma,u);
			u=0;
		}else{
			u++;
		}
	}
	ma=max(ma,u);
	u=0;
	for(int i=0;i<n;i++){
		if(!t[i]){
			u++;
		}else{
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(!t[i]){
			u++;
		}else{
			break;
		}
	}
	ma=max(ma,u);
	
	x=n/2;
	if(n%2){
		x-=ma/2;
	}else{
		if(ma>0){
			x--;
			ma--;
		}
		x-=ma/2;
	}
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++){
		t[(a[n+1-i]-i+n)%n]=1;
	}
	ma=0;
	
	u=0;
	for(int i=0;i<n;i++){
		if(t[i]){
			ma=max(ma,u);
			u=0;
		}else{
			u++;
		}
	}
	ma=max(ma,u);
	u=0;
	for(int i=0;i<n;i++){
		if(!t[i]){
			u++;
		}else{
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(!t[i]){
			u++;
		}else{
			break;
		}
	}
	ma=max(ma,u);
	
	y=n/2;
	if(n%2){
		y-=ma/2;
	}else{
		if(ma>0){
			y--;
			ma--;
		}
		y-=ma/2;
	}
	cout<<min(x,y);
	return 0;
}

