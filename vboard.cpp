#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=505;
ll n,q,o1,o2,o3,o4,a[N][N],x[N][N],y[N][N];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=0;i<=n;i++){
        x[i][0]=0;x[0][i]=0;
        y[i][0]=0;y[0][i]=0;
    }
    for (ll i=1;i<=n;i++)
		for (ll j=1;j<=n;j++)
			cin>>a[i][j];
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++)
            if ((i+j)%2==0){
                x[i][j]=a[i][j]+x[i-1][j]+x[i][j-1]-x[i-1][j-1];
                y[i][j]=y[i-1][j]+y[i][j-1]-y[i-1][j-1];
            }
            else if ((i+j)%2==1){
                x[i][j]=x[i-1][j]+x[i][j-1]-x[i-1][j-1];
                y[i][j]=a[i][j]+y[i-1][j]+y[i][j-1]-y[i-1][j-1];
            }
    cin>>q;
    while (q--){
        cin>>o1>>o2>>o3>>o4;
        cout<<abs(x[o3][o4]-x[o1-1][o4]-x[o3][o2-1]+x[o1-1][o2-1]-y[o3][o4]+y[o1-1][o4]+y[o3][o2-1]-y[o1-1][o2-1])<<endl;
    }
}

