#include<iostream>
#include<cstdio>
using namespace std;
int n,px[26][26],py[26][26],sx,sy,sum=0,a[26][26],num[10],bz;
bool pd[20005],v[26][26][20005];
char s[110];
void transfrom(int temp)
{
	for(int i=9;i>=1;i--)num[i]=temp%3,temp/=3;
}
int ksm(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1)c=c*a;
		a=a*a,b>>=1;
	}
	return c;
}
int transto()
{
	int temp=0;
	for(int i=9;i>=1;i--)temp+=num[i]*ksm(3,9-i);
	return temp;
}
void dfs(int x,int y,int temp)
{
	if(a[x][y]==-1)return;
	transfrom(temp);
	if(a[x][y]&&!num[(px[x][y]-1)*3+py[x][y]])num[(px[x][y]-1)*3+py[x][y]]=a[x][y],temp=transto();
	if(v[x][y][temp])return;
	v[x][y][temp]=1,bz=0;
	for(int i=1;i<=3;i++)
	{
		if(num[(i-1)*3+1]==2&&num[(i-1)*3+2]==1&&num[(i-1)*3+3]==1)bz=1;
		if(num[(i-1)*3+3]==2&&num[(i-1)*3+2]==1&&num[(i-1)*3+1]==1)bz=1;
	}
	for(int i=1;i<=3;i++)
	{
		if(num[i]==2&&num[i+3]==1&&num[i+6]==1)bz=1;
		if(num[i+6]==2&&num[i+3]==1&&num[i]==1)bz=1;
	}
	if(num[5]==1)
	{
		if((num[1]==2&&num[9]==1)||(num[9]==2&&num[1]==1))bz=1;
		if((num[3]==2&&num[7]==1)||(num[7]==2&&num[3]==1))bz=1;
	}
	if(bz)
	{
		sum+=!pd[temp],pd[temp]=1;return;
	}
	dfs(x+1,y,temp),dfs(x,y+1,temp),dfs(x-1,y,temp),dfs(x,y-1,temp);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=3;j<=3*n;j+=3)
		{
			if(s[j]=='#')a[i][j/3]=-1;
			else if(s[j]=='.')a[i][j/3]=0;
			else if(s[j]=='B')sx=i,sy=j/3;
			else
			{
				if(s[j-2]=='O')a[i][j/3]=1;
				else a[i][j/3]=2;
				px[i][j/3]=s[j-1]-'0',py[i][j/3]=s[j]-'0';
			}
		}
	}
	dfs(sx,sy,0);
	printf("%d",sum);
	return 0;
}

