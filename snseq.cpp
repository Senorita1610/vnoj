#include <bits/stdc++.h>

using namespace std;
const double eps=1e-8;
int main() {
    int a,i;
    double b;
    while(scanf("%d%lf",&a,&b)!=EOF){
        double ans=1e9;
        a--;
        for(i=1;i<=a;i++){
            double r=b-i*i;
            if(r/i+eps>-1&&(r/i<1+eps||i==a)) ans=min(ans,(a-i)*(a-i)-(a-i)*r/i);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}

