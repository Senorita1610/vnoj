#include<bits/stdc++.h>
using namespace std;
long double xa,ya,ra,xb,yb,rb,fa,fb,d;
int main(){
	cin>>xa>>ya>>ra>>xb>>yb>>rb;
	d=sqrt(pow(xa-xb,2)+pow(ya-yb,2));
	if(d>=ra+rb) return printf("0"),0;
	if(d<=abs(ra-rb)) return printf("%.8lf",double(pow(min(ra,rb),2)*acos(-1))),0;
	fa=acos((ra*ra-rb*rb+d*d)/2/ra/d)*2,fb=acos((rb*rb-ra*ra+d*d)/2/rb/d)*2;
	return printf("%.8lf",double(ra*ra*(fa-sin(fa))+rb*rb*(fb-sin(fb)))/2),0;
}

