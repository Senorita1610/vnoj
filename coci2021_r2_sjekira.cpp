#include<algorithm>
#include<cstdio>
#include<cstring>
namespace IO{
	const int ARR_SIZE=1<<20;
	#define gc() ((IO::si!=IO::ti||(IO::ti=(IO::si=IO::input)+fread(IO::input,1,IO::ARR_SIZE,stdin))),IO::si!=IO::ti?*(IO::si++):EOF)
	#define pc(ch) ((IO::o.so!=IO::o.to||(fwrite(IO::o.output,1,IO::ARR_SIZE,stdout),IO::o.so=IO::o.output)),*(IO::o.so++)=ch)
	char input[ARR_SIZE],*si=input,*ti=input;
	struct Output_Stream{
		char output[ARR_SIZE],*so=output,*to=output+ARR_SIZE;
		~Output_Stream(){
			if(so==output)return;
			fwrite(output,1,so-output,stdout);
			so=output;
		}
	}o;
	template<typename T>
	void read(T&num){
		int ch=gc();
		num=0;
		while(ch<48||ch>57)ch=gc();
		while(ch>=48&&ch<=57)num=(num<<3)+(num<<1)+(ch^48),ch=gc();
	}
	template<typename T>
	void write(T a){
		static int ch[50],cnt=0;
		if(a==0)pc('0');
		while(a)ch[++cnt]=a%10|48,a/=10;
		while(cnt)pc(ch[cnt--]);
	}
}
using IO::read;
using IO::write;
typedef long long ll;
const int maxn=100000;
int n,t[maxn+1];
int mx;
ll ans;
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(t[i]);
		mx=std::max(mx,t[i]);
		ans+=t[i];
	}
	ans-=mx;
	for(int i=1,x,y;i<n;i++){
		read(x),read(y);
		ans+=std::max(t[x],t[y]);
	}
	write(ans),pc('\n');
	return 0;
}

