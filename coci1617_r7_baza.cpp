#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
 
using namespace std ;
 
int32_t main ()
{
    fio
    int n , m ;
    cin >> n >> m ;
    int a[n][m] ;
    for ( int i = 0 ; i < n ; i++ ) for ( int k = 0 ; k < m ; k++ ) cin >> a[i][k] ;
    int q ;
    cin >> q ;
    int b[q][m] ;
    for ( int i = 0 ; i < q ; i++ ) for ( int k = 0 ; k < m ; k++ ) cin >> b[i][k] ;
    for ( int j = 0 ; j < q ; j++ )
    {
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ )
        {
            bool jean = 1 ;
            for ( int k = 0 ; k < m ; k++ )
            {
                if ( a[i][k] == b[j][k] || b[j][k] == -1 ) continue ;
                else
                {
                    jean = 0 ;
                    break ;
                }
            }
            if ( jean ) ans++ ;
        }
        cout << ans << "\n" ;
    }
    return 0 ;
}

