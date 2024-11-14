#include<bits/stdc++.h>
using namespace std;

long long n, ans, prime[1000006], f[1000006];
int main()
{
    prime[1] = 1;
    prime[0] = 1;
    for(int i = 2; i*i <= 1000000; ++i)
        if(prime[i] == 0)
            for(int j = i*i; j <= 1000000; j += i) 
                prime[j] = 1;

    int vt = 1;
    for(int i = 1; i <= 1000000; ++i)
        if(prime[i] == 0) 
            f[vt] = i, ++vt;

    for(int i = 1; i <= vt; ++i) 
        f[i] += f[i-1];
    while(cin >> n)
    {
        ans = 0;
        if(n==0) 
            break;
        for(int i = 1; i <= vt; ++i)
        {
            int k = lower_bound(f+i, f+vt+1, n+f[i-1]) - f;
            if(f[k] - f[i-1] == n)
             ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}

