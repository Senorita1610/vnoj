#include<bits/stdc++.h>
using namespace std;
int n;
int a[405][405],f[20];
long long res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        a[x+200][y+200]=1<<(c-1);
    }
    for(int i=1;i<=400;i++) for(int j=0;j<=i-1;j++){
        for(int k=0;k<=15;k++) f[k] = 0;
        for(int k=0;k<=400;k++){
            int u=a[i][k]|a[j][k];
            res+=f[15^u];
            f[u]++;
        }
    }
    cout<<res;
}

