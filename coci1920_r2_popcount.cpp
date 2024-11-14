#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct BigInt{
	static const int maxn = 256;
	unsigned char val[maxn];
	int len;
	inline void clear(){
		memset(val,0,sizeof(val));
		len = 0;
	}
	inline BigInt operator + (const BigInt &rhs)const{
		BigInt res;res.clear();
		res.len = max(len,rhs.len) + 1;
		for(int i = 1;i <= res.len;i++){
			res.val[i] += val[i] + rhs.val[i];
			res.val[i + 1] += res.val[i] / 10;
			res.val[i] %= 10;
		}
		if(!res.val[res.len])res.len--;
		return res; 
	}
	inline BigInt operator * (const BigInt &rhs)const{
		BigInt res;res.clear();
		res.len = len + rhs.len + 23;
		for(int i = 1;i <= len;i++)
			for(int j = 1;j <= rhs.len;j++){
				res.val[i + j - 1] += val[i] * rhs.val[j];
				res.val[i + j] += res.val[i + j - 1] / 10;
				res.val[i + j - 1] %= 10;
			}
		while(!res.val[res.len])res.len--;
		return res; 
	}
	inline void print(){
		for(int i = len;i >= 1;i--)putchar(val[i] + '0');
	}
}w[512],now;
int n,k,N,len,val[512],cnt;
int main(){
	scanf("%d %d",&n,&k);
	for(N = 1;N < n;N <<= 1);
	int tmp = N - 1;len = 1;
	w[0].len = 1;
	w[0].val[1] = 1;
	w[1].len = 1;
	w[1].val[1] = 2;
	for(int i = 2;i < 512;i++)w[i] = w[i - 1] * w[1];
	int ans;
	for(ans = 0;1 << ans <= tmp;ans++);
	printf("%d\n",ans);
	while(tmp){
		for(int i = 0;i < min(n,tmp * len);i++)
			val[i] = ((i / len) & 1) ^ 1;
		now.clear();
		for(int i = 0;i < min(n,tmp * len);i++)
			if(val[i])now = now + w[i];
		printf("A=((A&");
		now.print();
		printf(")+((A&");
		
		for(int i = 0;i < min(n,N);i++)
			val[i] = ((i / len) & 1);
		now.clear();
		for(int i = 0;i < min(n,N);i++)
			if(val[i])now = now + w[i];
		now.print();
		printf(")>>(1<<%d)))\n",cnt++);
		tmp >>= 1;
		len <<= 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

