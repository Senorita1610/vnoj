#include <stdio.h>
//#include <conio.h>
main()
{
long a[101],T,n,a1,c[15];
scanf("%ld",&T);
for(long i=1;i<=T;i++)
  {
  scanf("%ld",&n);
  a1=0;
  for(long j=1;j<=n;j++)
    {
    scanf("%ld",&a[j]);
    if(a[j]==1)
      a1++;
    }
  if(a1==n)
    {
    if(n%2!=0)
      printf("Brother\n");
    else printf("John\n");
    }
  else if(a1==n-1)
    printf("John\n");
  else
    {
    long max=0;
    long t=0;
    long kt=-1;                 
    for(long j=1;j<=n;j++)
      if(a[j]>max)
        max=a[j];
    while(max!=0)
      {
      t++; max=max/2;
      }
    //printf("%ld ",t);  
    for(long j=1;j<=t;j++)
      c[j]=0;  
    for(long j=1;j<=n;j++)
      for(long k=1;k<=t;k++)
        {
        c[k]=c[k]+a[j]%2;
        a[j]=a[j]/2;
        }
    for(long j=1;j<=t;j++)
       if(c[j]%2!=0)
         {
         kt=1;
         break;
         }
    if(kt==1)
      printf("John\n");
    else printf("Brother\n");
    }
  }  
//getch();
}

