#include <bits/stdc++.h>
 
using namespace std;
 
using ld = long double;
using ll = long long;
 
#define int ll
 
#define sz(x) (int)x.size()
 
signed main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<char>> from(n, vector<char>(m, ' '));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> from[i][j];
        }
    }
 
    auto to = from;
    for(int i=0; i+1<n; ++i){
        for(int j=0; j+1<m; ++j){
            if(from[i][j] == '#'){
                to[i][j+1] = '#';
                to[i+1][j] = '#';
                to[i+1][j+1] = '#';
            }
        }
    }
 
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cout << to[i][j];
        }
        cout << endl;
    }
    
}

