#include <bits/stdc++.h>
using namespace std;
 
const int oo = 1e9;
int matrix[1001][1001];
 
void floyd(int N) {
    for(int k=1;k<=N;++k) {
        for(int i=1;i<=N;++i) {
            for(int j=1;j<=N;++j) {
                matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
            }
        }
    }
}
main() {
    long long through[30001];
    int N,M;
    cin >> N >> M;
    for(int i=1;i<=M;++i) {
        cin >> through[i];
    }
    for(int i=1;i<=N;++i) {
        for(int j=1;j<=N;++j) {
            cin >> matrix[i][j];
        }
    }
    floyd(N);
    long long sum = 0;
    for(int i=2;i<=M;++i) {
        sum += matrix[through[i-1]][through[i]];
    }
    cout << sum << endl;
}

