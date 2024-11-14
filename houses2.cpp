#include<cmath>
#include<cstdio>
#include<vector>
using Lf = long double;
const int N = 100005;
const Lf inf = 1e9, eps = 1e-9;
int T;
struct Comp {
	Lf x,y;
	void read() {
		scanf("%Lf%Lf",&x,&y);
	}
	Comp operator+(const Comp& c) const {
		return {
			x+c.x,y+c.y
		};
	}
	Comp operator-(const Comp& c) const {
		return {
			x-c.x,y-c.y
		};
	}
	Lf operator&(const Comp& c) const {
		return x*c.x+y*c.y;
	}
	Lf operator|(const Comp& c) const {
		return x*c.y-y*c.x;
	}
	Comp operator*(Lf p) const {
		return {
			x*p,y*p
		};
	}
	Comp operator/(Lf p) const {
		return {
			x/p,y/p
		};
	}
	Comp operator~() const {
		return {x,-y};
	}
	Lf abs() const {
		return sqrt(x*x+y*y);
	}
}st,ed,pnt[3][3];
bool diff(const Comp& a,const Comp& b,const Comp& c,const Comp& d){
	return ((c-a)|(b-a))*((b-a)|(d-a))>0;
}
Lf dis[11][11];
int main(){
	scanf("%d",&T);
	while(T--){
		std::vector<Comp>v;
		std::vector<std::pair<Comp,Comp>>e;
		st.read(),ed.read();
		v.push_back(st),v.push_back(ed);
		for(int i=0;i<3;i++){
			std::vector<Comp>p,t;
			p.resize(3),t.resize(3);
			for(int j=0;j<3;j++) p[j].read();
			Comp g =(p[0]+p[1]+p[2])/3.0;
			for(int j=0;j<3;j++) t[j]=p[j]+(p[j]-g)*eps;
			for(int j=0;j<3;j++){
				e.push_back({t[j],t[(j+1)%3]});
				v.push_back(t[j]+(t[j]-g)*eps);
			}
		}
		for(int i=0;i<=10;i++){
			for(int j=0;j<=10;j++){
				if(i!=j){
					bool ok=true;
					for(auto pr:e){
						ok &=(!diff(v[i],v[j],pr.first,pr.second)|| !diff(pr.first,pr.second,v[i],v[j]));
					}
					if(ok)  dis[i][j]=(v[i]-v[j]).abs();
					else dis[i][j]=inf;
				}
				else{
					dis[i][j]=0;
				}
			}
		}
		for(int k=0;k<=10;k++){
			for(int i=0;i<=10;i++){
				for(int j=0;j<=10;j++){
					dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		printf("%.5Lf\n",dis[0][1]);
	}
	return 0;
}

