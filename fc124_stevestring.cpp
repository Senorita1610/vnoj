#include<stdio.h>

int main()
{
    int t,i,ca,cb,cc;
    char arr[150]={0};

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",arr);

        ca=cb=cc=0;

        for(i=0;arr[i];i++)
        {
            if(arr[i]=='a') ca++;
            else if(arr[i]=='b') cb++;
            else cc++;
        }

        if((ca|cb)==0) printf("%d\n",cc);
        else if((cb|cc)==0) printf("%d\n",ca);
        else if((ca|cc)==0) printf("%d\n",cb);
        else if((ca&1)&&(cb&1)&&(cc&1)) printf("2\n");
        else if((!(ca&1))&&(!(cb&1)&&(!(cc&1)))) printf("2\n");
        else printf("1\n");
    }

    return 0;
}

