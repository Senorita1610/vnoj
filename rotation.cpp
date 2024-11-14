#include <bits/stdc++.h> 
using namespace std ;
int n , a , b , c ;
bool flag ; 
int main()
{
	cin >> n ;
	for( int i = 1 ; i < n ; ++i ){
		cin >> a >> b >> c ;
		if( c == 1 ) flag = !flag ;
	}
	cout << flag ? 0 : 1 ;
	return 0 ; 
}

