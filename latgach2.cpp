#include <cstdio>
#include <iostream>
//#include <conio.h>
#define base 100000000

using namespace std;

struct solon
{
     int so;
     int a[200];
};

solon f[1010];
int n,r[10],mu2[10],rong;

solon tong (solon A,solon B)
{
      int du = 0;
      solon C;
      if(A.so<B.so)
      {
           C = A;
           A = B;
           B = C;
      }
      for(int i = B.so+1;i<=A.so;i++) B.a[i] = 0;
      C.so = A.so;
      for(int i = 1;i<=A.so;i++)
      {
          C.a[i] = (A.a[i]+B.a[i]+du)%base;
          du = (A.a[i]+B.a[i]+du)/base;
      }
      if(du>0) {C.so++; C.a[C.so] = du;}
      return C;
}

solon tichnho(solon A,long long k,int chuso)
{
      solon C;
      long long du = 0;
      C.so = A.so+chuso;
      for(int i = 1;i<=chuso;i++)
           C.a[i] = 0;
      for(int i = chuso+1;i<=chuso+A.so;i++)
      {
           C.a[i] = (A.a[i-chuso]*k+du)%base;
           du = (A.a[i-chuso]*k+du)/base;
      }
      if(du>0) {C.so++; C.a[C.so] = du;}
      return C;
}

solon tich(solon A,solon B)
{
      solon C;
      C.so = 1; C.a[1] = 0;
      for(int i = 1;i<=B.so;i++)
      {
           C = tong(C,tichnho(A,B.a[i],i-1));
      }
      return C;
}

void print(solon A)
{
      printf("%d",A.a[A.so]);
      for(int i = A.so-1;i>=1;i--)
          printf("%08d",A.a[i]);
}

int main()
{
      mu2[0] = 1; for(int i = 1;i<=10;i++) mu2[i]=mu2[i-1]*2;
      f[0].so = 1; f[0].a[1] = 1;
      f[1].so = 1; f[1].a[1] = 1;
      for(int i = 2;i<=1000;i++) f[i] = tong(f[i-1],f[i-2]);
      while(scanf("%d",&n)>0)
      {
           if(n==3) printf("196\n");
           else{
               solon KQ,nhan;int lan;
               KQ.so = 1; KQ.a[1] = 2;
               for(int i = 0;i<81;i++)
               {
                     int the = i;
                     for(int j = 1;j<=4;j++){
                          r[j] = the%3;
                          the/=3;
                     }
                     r[5] = r[1];
                     nhan.so = 1; nhan.a[1] = 1;
                     lan = 0;
                     for(int j = 1;j<=4;j++){
                          rong = n-2;
                          if(r[j]==2) rong--;
                          if(r[j+1]==1) rong--;
                          if(r[j]==0) lan++;
                          nhan = tich(nhan,f[rong]);
                     }
                     nhan = tichnho(nhan,mu2[lan],0);
                     KQ = tong(KQ,nhan);
               }
               print(KQ);
               printf("\n");
           }     
      }
}

