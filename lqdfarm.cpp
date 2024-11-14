#include <cstdio>
#include <algorithm>
#include <functional> 
using namespace std;

#define MAXQ 160000
#define MAXFS 2000

int T, Q, S, F, i, j, k, sum, sol;
int field[MAXFS], strip[MAXFS];
bool mark[MAXQ];

int main() {
    scanf( "%d %d %d", &Q, &F, &S );

    sum = 0;
    fill( mark, mark + Q + 1, 0 );

    for ( i = 0; i < F; i++ ) {
      scanf( "%d", &field[i] );
      sum += field[i];
    }

    for ( i = 0; i < S; i++ )
      scanf( "%d", &strip[i] );

    if ( sum < Q ) {

      sort( strip, strip + S, greater< int >() );

      for ( i = 0; i < S && sum < Q; i++ )
        sum += strip[i];

      sol = Q - i;
    }
    else if ( sum > Q ) {

      mark[0] = true;
      sort( field, field + F );

      for ( i = k = 0; i < F && !mark[Q]; i++ ) {

        for ( j = k; j >= 0; j-- )
          if ( mark[j] )
            mark[ j + field[i] ] = true;

        if ( k < Q )
          k += field[i];
      }

      sol = Q - !mark[Q];
    }
    else 
      sol = Q;

    printf( "%d\n", sol );
}

