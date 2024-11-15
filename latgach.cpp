#include<stdio.h>
#include<string.h>
main()
{
int x,a[100],i,b[23],c[23],m;
scanf("%d",&x);
for(int j=0;j<x;j++)
  scanf("%d",&a[j]);
for(int j=0;j<x;j++)
  {
  for(int k=0;k<=21;k++)
    { b[k]=0;c[k]=0; }
  b[22]=0;
  c[22]=1;
  i=0;
  while(1)
    {
    for(int t=22;t>=0;t--)
      {   m=b[t];
          b[t]=(b[t]+c[t])%10;
          if(b[t]<c[t]||m==10)
          b[t-1]++;
      }
    i++;
    if(i==a[j])
      {
      int u=0;
      for(int t=0;t<=22;t++)
        { u+=b[t];
          if(u==0) continue;
          printf("%d",b[t]%10);
        }
      printf("\n");
      break;
      }
    for(int t=22;t>=0;t--)
      {   m=c[t];
          c[t]=(b[t]+c[t])%10;
          if(c[t]<b[t]||m==10)
          c[t-1]++;
      }
    i++;
    if(i==a[j])
      {
      int u=0;
      for(int t=0;t<=22;t++)
        { u+=c[t];
          if(u==0) continue;
          printf("%d",c[t]%10);
        }
      printf("\n");
      break;
      }
    }
  }
}

