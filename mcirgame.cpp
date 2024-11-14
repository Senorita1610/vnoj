#include <cstdio>
#include <iostream>
using namespace std;
bool operator>(string a, string b)
{
    if(a.length()>b.length())
        return true;
    else if(a.length()<b.length())
        return false;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]>b[i])
            return true;
        else if(a[i]<b[i])
            return false;
    }
    return true;
}
string operator+(string a, string b)
{
    while(a.length()<b.length())
        a = '0' + a;
    while(a.length()>b.length())
        b = '0' + b;
    string c;
    int s, r = 0;
    char ch;
    for(int i=a.length()-1; i>=0; i--)
    {
        s = (a[i]-'0') + (b[i]-'0') + r;
        r = s/10;
        ch = (s%10)+'0';
        c = ch + c;
    }
    if(r>0)
    {
        ch = r+'0';
        c = ch+c;
    }
    return c;
}
string operator-(string a, string b)
{
    while(a.length()<b.length())
        a = '0'+a;
    while(a.length()>b.length())
        b = '0'+b;
    string c;
    int s, r = 0;
    char ch;
    for(int i=a.length()-1; i>=0; i--)
    {
        s = a[i]-b[i]-r;
        if(s<0)
        {
            s += 10;
            r = 1;
        }
        else
            r = 0;
        ch = (s%10)+'0';
        c = ch+c;
    }
    while(c[0]=='0' && c.length()>1)
        c.erase(0, 1);
    return c;
}
string operator*(string a, string b)
{
    int s, r = 0, len = a.length()+b.length()-1;
    string c;
    char ch;
    for(int i=len-1; i>=0; i--)
    {
        s = 0;
        for(int j=0; j<=i; j++)
            if(j<a.length() && (i-j)<b.length())
                s += (a[j]-'0')*(b[i-j]-'0');
        s += r;
        r = s/10;
        ch = (s%10)+'0';
        c = ch+c;
    }
    if(r>0)
    {
        ch = r + '0';
        c = ch + c;
    }
    return c;
}
int main()
{
    string c[152];
    c[1] = "1";
    for(int i=2; i<=151; i++)
    {
        c[i] = "0";
        for(int j=1; j<i; j++)
        {
            c[0] = c[j]*c[i-j];
            c[i] = c[0]+c[i];
        }
    }
    int a;
    while(true)
    {
        scanf("%d", &a);
        if(a==-1)
            break;
        printf("%s\n", c[a+1].c_str());
    }
    return 0;
}

