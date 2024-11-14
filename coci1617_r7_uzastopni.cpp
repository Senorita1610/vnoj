#include<bits/stdc++.h>
 
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif
 
using namespace std;
 
constexpr int sz = 1e5 + 5;
 
#define int long long
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long N;
	cin >> N;
	N <<= 1;
	for(register int i = 1; 1ll * i * i <= N; ++i){
		if(N % i == 0){
			
			if((i + N / i + 1) % 2 == 0){
				int b = (i + N / i + 1) / 2;
				int a = b - i; --b;
				if(a > 0 && b > 0 && b > a){
					cout << a << ' ' << b << '\n';
				}
			}
			
		}
		
		
	}
	
	return 0;
}

