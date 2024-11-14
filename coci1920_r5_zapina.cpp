#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<vector<long long>> Pascal(N + 2, vector<long long>(N + 2, 0));
    for (int i = 0; i <= N; i++)
    {
        Pascal[i][0] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N + 1; j++)
        {
            Pascal[i][j] = (Pascal[i - 1][j] + Pascal[i - 1][j - 1]) % 1000000007;
        }
    }
    long long tot = 1;
    for (int i = 0; i < N; i++)
    {
        tot = (tot * N) % 1000000007;
    }
    vector<vector<long long>> tab(N + 1, vector<long long>(N + 1, 0));
    tab[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (tab[i][j] == 0)
                continue;
            for (int k = 0; k <= N - j; k++)
            {
                if (k == i + 1)
                    continue;
                tab[i + 1][j + k] += tab[i][j] * Pascal[N - j][k];
                tab[i + 1][j + k] = tab[i + 1][j + k] % 1000000007;
            }
        }
    }
    tot += 1000000007;
    tot = (tot - tab[N][N]) % 1000000007;
    cout << tot;
}

