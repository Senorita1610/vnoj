#include<bits/stdc++.h>
using namespace std; 
#define PB push_back 
#define MP make_pair 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
typedef long long LL; 
typedef pair<int,int> PII; 
const int maxn = 2008; 
bool a[maxn][maxn]; 
int l[maxn][maxn],r[maxn][maxn],u[maxn][maxn];  
set<pair<int,int>>h; 
int main(){
	int n,M,X0,A,B,Y0,C,D;
	cin>>n>>M>>X0>>A>>B>>Y0>>C>>D;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
      		a[i][j]=true; 
      		l[i][j] = r[i][j] = u[i][j] = 0; 
    	}
	}
    X0%=n;Y0%=n; 
    for(int i=0;i<M;i++) 
    { 
      a[X0+1][Y0+1] = false; 
      X0 = (X0*A+B)%n; 
      Y0 = (Y0*C+D)%n; 
    } 
    for(int i=1;i<=n;i++) 
    { 
      for(int j=1;j<=n;j++) if(a[i][j]) u[i][j] = u[i-1][j]+1; 
      for(int j=1;j<=n;j++) if(a[i][j]) l[i][j] = l[i][j-1]+1; 
      for(int j=n;j;j--) if(a[i][j]) r[i][j] = r[i][j+1]+1; 
    } 
 
    int ans = 0; 
    for(int i=1;i<=n;i++) 
    { 
    	h.clear();
    for(int j=1;j<=n;j++)if(a[i][j]) 
    { 
      if(u[i][j]>1) 
      { 
        l[i][j] = min(l[i][j],l[i-1][j]); 
        r[i][j] = min(r[i][j],r[i-1][j]); 
      } 
      if(r[i+1][j-l[i][j]+1]<l[i][j]+r[i][j]-1) 
      if(h.find( MP(j-l[i][j],j+r[i][j]) )==h.end()) 
      { 
        h.insert( MP(j-l[i][j],j+r[i][j]) ); 
        ans++; 
      } 
    } 
	}
	cout<<ans;
}

